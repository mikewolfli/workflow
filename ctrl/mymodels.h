#include <wx/dataview.h>

class MyProjectTreeModelNode;
WX_DEFINE_ARRAY_PTR( MyProjectTreeModelNode*, MyProjectTreeModelNodePtrArray );


class MyProjectTreeModelNode
{
public:
    MyProjectTreeModelNode( MyProjectTreeModelNode* parent,
                          const wxString &wbs, const wxString &lift_id,
                          const wxString &elevator_type, const wxString &project_type,
                          const wxString &req_finish, const wxString &res_person, const int level )
    {
        m_parent = parent;

        m_wbs = wbs;
        m_index = m_wbs.Left(10);
        m_lift_id = lift_id;
        m_elevator_type = elevator_type;
        m_project_type = project_type;
        m_req_finish = req_finish;
        m_res_person = res_person;
        m_level = level;
        if(res_person.IsEmpty())
           m_status = 0;
        else m_status = 1;

        prj_status = 1;
        is_urgent = false;


        m_container = false;
    }

    MyProjectTreeModelNode( MyProjectTreeModelNode* parent, const wxString &index,
                          const wxString &branch, const int level )
    {
        m_parent = parent;

        m_index = index;
        m_wbs = branch;
        m_lift_id = wxEmptyString;
        m_elevator_type = wxEmptyString;
        m_project_type = wxEmptyString;
        m_req_finish = wxEmptyString;
        m_res_person = wxEmptyString;
        m_level = level;
        m_status = -1;

        prj_status = 1;
        is_urgent = false;

        m_container = true;
    }

    ~MyProjectTreeModelNode()
    {
        // free all our children nodes
        size_t count = m_children.GetCount();
        for (size_t i = 0; i < count; i++)
        {
            MyProjectTreeModelNode *child = m_children[i];
            delete child;
        }
    }

    bool IsContainer() const
        { return m_container; }

    MyProjectTreeModelNode* GetParent()
        { return m_parent; }
    MyProjectTreeModelNodePtrArray& GetChildren()
        { return m_children; }
    MyProjectTreeModelNode* GetNthChild( unsigned int n )
        { return m_children.Item( n ); }
    void Insert( MyProjectTreeModelNode* child, unsigned int n)
        { m_children.Insert( child, n); }
    void Append( MyProjectTreeModelNode* child )
        { m_children.Add( child ); }
    unsigned int GetChildCount() const
        { return m_children.GetCount(); }

    wxDataViewItem GetItem() const
        { return wxDataViewItem( (void*) this ); }

public:     // public to avoid getters/setters
    wxString                m_index; //此列隐藏
    wxString                m_wbs;
    wxString                m_lift_id;
    wxString                m_elevator_type;
    wxString                m_project_type;
    wxString                m_req_finish;
    wxString                m_res_person;
    int                     m_status;//确定行的状态， -1 无关，树枝节点， 0 未指定执行人， 1 指定执行人，但未更新系统系统更新， 2 指定执行人，同时已经系统更新。
    int prj_status;
    // TODO/FIXME:
    // the GTK version of wxDVC (in particular wxDataViewCtrlInternal::ItemAdded)
    // needs to know in advance if a node is or _will be_ a container.
    // Thus implementing:
    //   bool IsContainer() const
    //    { return m_children.GetCount()>0; }
    // doesn't work with wxGTK when MyProjectTreeModel::AddToClassical is called
    // AND the classical node was removed (a new node temporary without children
    // would be added to the control)
    bool m_container;
    int m_level;
    bool is_urgent;

private:
    MyProjectTreeModelNode          *m_parent;
    MyProjectTreeModelNodePtrArray   m_children;
};


// ----------------------------------------------------------------------------
// MyProjectTreeModel
// ----------------------------------------------------------------------------

/*
Implement this data model
   索引       项目信息         梯号        梯型          项目类型       配置完成日期     配置工程师
   index         wbs            lift_id     elevator_type  project_type  req_finish  res_person
--------------------------------------------------------------------------
1: 项目清单:
    2:  合同号+项目名称
        3:  wbs no          梯号        梯型          项目类型       配置完成日期    配置工程师
*/

class MyProjectTreeModel: public wxDataViewModel
{
public:
    MyProjectTreeModel();
    ~MyProjectTreeModel()
    {
        delete m_root;
        delete m_attr;
    }

    // helper method for wxLog
    wxString Get_Index( const wxDataViewItem &item ) const;
    wxString Get_wbs( const wxDataViewItem &item ) const;
    wxString Get_lift_id( const wxDataViewItem &item ) const;
    wxString Get_elevator_type( const wxDataViewItem &item ) const;
    wxString Get_project_type( const wxDataViewItem &item ) const;
    wxString Get_req_finish( const wxDataViewItem &item ) const;
    wxString Get_res_person( const wxDataViewItem &item ) const;
    int Get_level( const wxDataViewItem &item ) const;
    int Get_levels()
    {
        return m_levels;
    };
    // helper methods to change the model

    MyProjectTreeModelNode* AddToRoot(const wxString &index, const wxString &branch );
    void AddToBranch(MyProjectTreeModelNode *l_parent, const wxString &branch, const wxString &wbs, const wxString &lift_id,
                          const wxString &elevator_type, const wxString &project_type,
                          const wxString &req_finish, const wxString &res_person);
    void Delete( const wxDataViewItem& item );

    void DeleteChildren( const wxDataViewItem& item );

    void DeleteAllItems();

    MyProjectTreeModelNode* GetNthChild(MyProjectTreeModelNode *parent,unsigned int pos);

    bool ChangeValue(const wxVariant& variant,
                     const wxDataViewItem& item,
                     unsigned int col)
    {
        return SetValue(variant, item, col) && ValueChanged(item, col);
    }

//    MyProjectTreeModelNode *  FindNode( const wxDataViewItem &item ) const;
 //   MyProjectTreeModelNode *  FindContainerNode( const wxDataViewItem &item ) const;
    MyProjectTreeModelNode *  SearchValue(MyProjectTreeModelNode *parent, const wxVariant &value, int level, int col);
    int HasContainer( const wxDataViewItem &item );
    bool IsBlank();

    // override sorting to always sort branches ascendingly

    int Compare( const wxDataViewItem &item1, const wxDataViewItem &item2,
                 unsigned int column, bool ascending ) const;

    // implementation of base class virtuals to define model

    virtual unsigned int GetColumnCount() const
    {
        return 6;
    }

    virtual wxString GetColumnType( unsigned int col ) const
    {
         if (col == 5)
            return wxT("DateTime");

        return wxT("String");
    }

    virtual void GetValue( wxVariant &variant,
                           const wxDataViewItem &item, unsigned int col ) const;
    virtual bool SetValue( const wxVariant &variant,
                           const wxDataViewItem &item, unsigned int col );



    virtual bool IsEnabled( const wxDataViewItem &item,
                            unsigned int col ) const;

    virtual bool GetAttr(const wxDataViewItem &item, unsigned int col, wxDataViewItemAttr &attr) const;

    virtual wxDataViewItem GetParent( const wxDataViewItem &item ) const;
    virtual bool IsContainer( const wxDataViewItem &item ) const;
    virtual unsigned int GetChildren( const wxDataViewItem &parent,
                                      wxDataViewItemArray &array ) const;

    wxDataViewItem  get_root()
    {
        wxASSERT(m_root);

        return wxDataViewItem(m_root);
    }
private:
    MyProjectTreeModelNode*   m_root;
    wxDataViewItemAttr* m_attr;

    int m_levels;
};

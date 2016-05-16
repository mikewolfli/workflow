#include <wx/dataview.h>
#include "./interface/wxPostgreSQL.h"

class wfTreeModelNode;
WX_DEFINE_ARRAY_PTR( wfTreeModelNode*, wfTreeModelNodePtrArray );

int str_to_catalog(wxString str_catalog);
wxString catalog_to_str(int i_catalog);
class wfTreeModelNode
{
public:

    wfTreeModelNode(const wxString & _branch)
    {
        m_parent = NULL;

        m_wbs = _branch;
        m_level = 0;
        m_container = true;

   //     m_attr = new wxDataViewItemAttr();
    }


    wfTreeModelNode( wfTreeModelNode* parent,
                          wxPostgreSQLresult *_res,int _level)
    {
        m_parent = parent;
        m_level = _level;

        if(m_level == 1)
        {
           m_wbs = _res->GetVal(wxT("instance_id")).Left(10);
        }

        m_container = true;
        m_proj_name= _res->GetVal(wxT("project_name"));

        if(m_level == 2)
        {
            m_wbs = _res->GetVal(wxT("instance_id"));
            m_lift_no=_res->GetVal(wxT("lift_no"));
            m_elevator_type=_res->GetVal(wxT("elevator_type"));
            m_proj_catalog=catalog_to_str(_res->GetInt(wxT("project_catalog")));
            m_req_finish=DateToStrFormat(_res->GetDate(wxT("req_configure_finish")));
            m_proj_status = _res->GetVal(wxT("action_name"));
            m_res=_res->GetVal(wxT("name"));
            m_progress = _res->GetLong(wxT("ins_progress"));
            m_container = false;
        }


 //       _res = 0;

   //     m_attr = new wxDataViewItemAttr();
    }

    ~wfTreeModelNode()
    {
        // free all our children nodes
        size_t count = m_children.GetCount();
        for (size_t i = 0; i < count; i++)
        {
            wfTreeModelNode *child = m_children[i];
            delete child;
        }

     //   delete m_attr;
    }

    bool IsContainer() const
        { return m_container; }

    wfTreeModelNode* GetParent()
        { return m_parent; }
    wfTreeModelNodePtrArray& GetChildren()
        { return m_children; }
    wfTreeModelNode* GetNthChild( unsigned int n )
        { return m_children.Item( n ); }
    void Insert( wfTreeModelNode* child, unsigned int n)
        { m_children.Insert( child, n); }
    void Append( wfTreeModelNode* child )
        { m_children.Add( child ); }
    unsigned int GetChildCount() const
        { return m_children.GetCount(); }

 /*   void SetBackgroundColour (const wxColour &colour)
    {
        m_attr->SetBackgroundColour(colour);
    }*/

public:     // public to avoid getters/setters
    wxString m_wbs;
    wxString m_proj_name;
    wxString m_lift_no;
    wxString m_elevator_type;
    wxString m_proj_catalog;
    wxString m_req_finish;
    wxString m_proj_status;
    wxString m_res;
    long m_progress;
    int m_level;

    // TODO/FIXME:
    // the GTK version of wxDVC (in particular wxDataViewCtrlInternal::ItemAdded)
    // needs to know in advance if a node is or _will be_ a container.
    // Thus implementing:
    //   bool IsContainer() const
    //    { return m_children.GetCount()>0; }
    // doesn't work with wxGTK when MyMusicTreeModel::AddToClassical is called
    // AND the classical node was removed (a new node temporary without children
    // would be added to the control)
    bool m_container;
 //   wxDataViewItemAttr* m_attr;

private:
    wfTreeModelNode          *m_parent;
    wfTreeModelNodePtrArray   m_children;

};

class wxDataViewTreeModel : public wxDataViewModel
{
    public:
        wxDataViewTreeModel();
        virtual ~wxDataViewTreeModel()
        {
            delete m_root;
        }

    // helper methods to change the model
    wfTreeModelNode* AddToRoot(wxPostgreSQLresult *_res);
    void AddToNode(wfTreeModelNode *_parent,  wxPostgreSQLresult *_res);
    void Delete( const wxDataViewItem &item );

    void DeleteAllItems();

    wfTreeModelNode* SearchValue(wfTreeModelNode *parent, const wxVariant &value, int level, int col);
    int  GetChildrenCount( const wxDataViewItem &item );

  /*  bool ChangeValue(const wxVariant& variant,
                     const wxDataViewItem& item,
                     unsigned int col)
    {
        return SetValue(variant, item, col) && ValueChanged(item, col);
    }
*/
    int HasContainer( const wxDataViewItem &item );
    bool IsBlank();

    wxDataViewItem  get_root()
    {
        wxASSERT(m_root);

        return wxDataViewItem((void *) m_root);
    }


    // override sorting to always sort branches ascendingly

  /*  int Compare( const wxDataViewItem &item1, const wxDataViewItem &item2,
                 unsigned int column, bool ascending ) const;*/

    // implementation of base class virtuals to define model

    virtual unsigned int GetColumnCount() const
    {
        return 9;
    }

    virtual wxString GetColumnType( unsigned int col ) const
    {

        return wxT("string");
    }

    virtual void GetValue( wxVariant &variant,
                           const wxDataViewItem &item, unsigned int col ) const;
    virtual bool SetValue( const wxVariant &variant,
                           const wxDataViewItem &item, unsigned int col );
 /*   virtual bool  GetAttr(const wxDataViewItem &item, unsigned int col,
                           wxDataViewItemAttr &attr) const;*/

    virtual bool IsEnabled( const wxDataViewItem &item,
                            unsigned int col ) const;

    virtual wxDataViewItem GetParent( const wxDataViewItem &item ) const;
    virtual bool IsContainer( const wxDataViewItem &item ) const;
    virtual unsigned int GetChildren( const wxDataViewItem &parent,
                                      wxDataViewItemArray &array ) const;

    protected:
    private:

        wfTreeModelNode*   m_root;
};


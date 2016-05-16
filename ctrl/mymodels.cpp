#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "mymodels.h"

// ----------------------------------------------------------------------------
// MyProjectTreeModel
// ----------------------------------------------------------------------------

MyProjectTreeModel::MyProjectTreeModel()
{
    m_root = new MyProjectTreeModelNode( NULL, wxEmptyString,  "配置项目", 0);

    m_attr = new wxDataViewItemAttr;
    m_levels = 3;
}

wxString MyProjectTreeModel::Get_Index( const wxDataViewItem &item ) const
{
    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return wxEmptyString;

    return node->m_index;
}

wxString MyProjectTreeModel::Get_wbs( const wxDataViewItem &item ) const
{
    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return wxEmptyString;

    return node->m_wbs;
}

wxString MyProjectTreeModel::Get_lift_id( const wxDataViewItem &item ) const
{
    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return wxEmptyString;

    return node->m_lift_id;
}

wxString MyProjectTreeModel::Get_elevator_type( const wxDataViewItem &item ) const
{
    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return wxEmptyString;

    return node->m_elevator_type;
}

wxString MyProjectTreeModel::Get_project_type( const wxDataViewItem &item ) const
{
    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return wxEmptyString;

    return node->m_project_type;
}

wxString MyProjectTreeModel::Get_req_finish( const wxDataViewItem &item ) const
{
    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return wxEmptyString;

    return node->m_req_finish;
}

wxString MyProjectTreeModel::Get_res_person( const wxDataViewItem &item ) const
{
    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return wxEmptyString;

    return node->m_res_person;
}

int MyProjectTreeModel::Get_level( const wxDataViewItem &item ) const
{
    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return -1;

    return node->m_level;
}

MyProjectTreeModelNode* MyProjectTreeModel::AddToRoot( const wxString &index, const wxString &branch )
{
    if (!m_root)
    {
        m_root = new MyProjectTreeModelNode( NULL, wxEmptyString, _("配置项目"), 0);
        m_levels = 3;
    }

    wxASSERT(m_root);
    // add to the new node to the root;
    MyProjectTreeModelNode *child_node =
        new MyProjectTreeModelNode( m_root, index,  branch, 1 );
    m_root->Append( child_node );

    // notify control
    wxDataViewItem child( (void*) child_node );
    wxDataViewItem parent( (void*) m_root );
    ItemAdded( parent, child );

    return child_node;
}

void MyProjectTreeModel::AddToBranch(MyProjectTreeModelNode *l_parent, const wxString &branch, const wxString &wbs, const wxString &lift_id,
                                     const wxString &elevator_type, const wxString &project_type,
                                     const wxString &req_finish, const wxString &res_person)
{
    if(!l_parent)
    {
        AddToRoot(wbs.Left(10), branch);
    }


    // add to the new node to the parent;
    MyProjectTreeModelNode *child_node =
        new MyProjectTreeModelNode( l_parent, wbs, lift_id, elevator_type, project_type, req_finish, res_person, 2);
    l_parent->Append( child_node );

    // notify control
    wxDataViewItem child( (void*) child_node );
    wxDataViewItem parent( (void*) l_parent );
    ItemAdded( parent, child );
}

MyProjectTreeModelNode* MyProjectTreeModel::GetNthChild(MyProjectTreeModelNode *parent, unsigned int pos)
{
    if(!parent)
        return NULL;

    return parent->GetNthChild(pos);
}

void MyProjectTreeModel::DeleteChildren( const wxDataViewItem& item )
{
    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();
    if (!node) return;

    node->GetChildren().clear();
}

void MyProjectTreeModel::DeleteAllItems()
{
    DeleteChildren(wxDataViewItem(m_root));
}

void MyProjectTreeModel::Delete( const wxDataViewItem& item )
{
    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return;

    wxDataViewItem parent( node->GetParent() );
    if (!parent.IsOk())
    {
        wxASSERT(node == m_root);

        // don't make the control completely empty:
        wxLogMessage( _("根节点无法删除!" ));
        return;
    }

    // first remove the node from the parent's array of children;
    // NOTE: MyProjectTreeModelNodePtrArray is only an array of _pointers_
    //       thus removing the node from it doesn't result in freeing it
    node->GetParent()->GetChildren().Remove( node );

    // free the node
    delete node;

    // notify control
    ItemDeleted( parent, item );

}

int MyProjectTreeModel::Compare( const wxDataViewItem &item1, const wxDataViewItem &item2,
                                 unsigned int column, bool ascending ) const
{
    wxASSERT(item1.IsOk() && item2.IsOk());
    // should never happen

    if (IsContainer(item1) && IsContainer(item2))
    {
        wxVariant value1, value2;
        GetValue( value1, item1, 1 );
        GetValue( value2, item2, 1 );

        wxString str1 = value1.GetString();
        wxString str2 = value2.GetString();
        int res = str1.Cmp( str2 );
        if (res) return res;

        // items must be different
        wxUIntPtr litem1 = (wxUIntPtr) item1.GetID();
        wxUIntPtr litem2 = (wxUIntPtr) item2.GetID();

        return litem1-litem2;
    }

    return wxDataViewModel::Compare( item1, item2, column, ascending );
}

void MyProjectTreeModel::GetValue( wxVariant &variant,
                                   const wxDataViewItem &item, unsigned int col ) const
{
    wxASSERT(item.IsOk());

    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();


    switch (col)
    {
    case 0:
        variant = node->m_wbs;
        break;

    case 1:
        variant = node->m_index;
        break;
    case 2:
        variant = node->m_lift_id;
        break;
    case 3:
        variant = node->m_elevator_type;
        break;
    case 4:
        variant = node->m_project_type;
        break;
    case 5:
        variant = node->m_req_finish;
        break;
    case 6:
        variant = node->m_res_person;
        break;
    default:
        wxLogMessage( _("MyProjectTreeModel::GetValue: wrong column %d"), col );
    }
}

bool MyProjectTreeModel::SetValue( const wxVariant &variant,
                                   const wxDataViewItem &item, unsigned int col )
{
    wxASSERT(item.IsOk());

    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();
    switch (col)
    {
    case 0:
        node->m_wbs = variant.GetString();
        return true;

    case 1:
        node->m_index = variant.GetString();
        return true;
    case 2:
        node->m_lift_id = variant.GetString();
        return true;
    case 3:
        node->m_elevator_type = variant.GetString();
        return true;
    case 4:
        node->m_project_type = variant.GetString();
        return true;
    case 5:
        node->m_req_finish = variant.GetString();
        return true;
    case 6:
        node->m_res_person = variant.GetString();
        return true;

    default:
        wxLogMessage( _("MyProjectTreeModel::SetValue: wrong column" ), col);
    }
    return false;
}

bool MyProjectTreeModel::GetAttr(const wxDataViewItem &item, unsigned int col, wxDataViewItemAttr &attr) const
{
    wxASSERT(item.IsOk());

    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();

     if(node->prj_status == 4)
        m_attr->SetBackgroundColour(*wxRED);
     else if(node->is_urgent)
        m_attr->SetBackgroundColour(*wxGREEN);
     else m_attr->SetBackgroundColour(*wxWHITE);


    attr = *m_attr;

    return true;

}


bool MyProjectTreeModel::IsEnabled( const wxDataViewItem &item,
    unsigned int col ) const
{
      wxASSERT(item.IsOk());

 /*   MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();*/

 //   return !(col == 7);
      return true;
}
/*
MyProjectTreeModelNode *  MyProjectTreeModel::FindNode( const wxDataViewItem &item ) const
{
    if (!item.IsOk())
        return m_root;

    return (MyProjectTreeModelNode*) item.GetID();
}

MyProjectTreeModelNode * MyProjectTreeModel::FindContainerNode( const wxDataViewItem &item ) const
{
    if (!item.IsOk())
        return (MyProjectTreeModelNode*) m_root;

    MyProjectTreeModelNode* node = (MyProjectTreeModelNode*) item.GetID();

    if (!node->IsContainer())
        return NULL;

    return (MyProjectTreeModelNode*) node;

}
*/
wxDataViewItem MyProjectTreeModel::GetParent( const wxDataViewItem &item ) const
{
    // the invisible root node has no parent
    if (!item.IsOk())
        return wxDataViewItem(0);

    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();

    // "MyMusic" also has no parent
    if (node == m_root)
        return wxDataViewItem(0);

    return wxDataViewItem( (void*) node->GetParent() );
}

bool MyProjectTreeModel::IsContainer( const wxDataViewItem &item ) const
{
    // the invisble root node can have children
    // (in our model always "MyMusic")
    if (!item.IsOk())
        return true;

    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();
    return node->IsContainer();
}

unsigned int MyProjectTreeModel::GetChildren( const wxDataViewItem &parent,
         wxDataViewItemArray &array ) const
{
    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) parent.GetID();
    if (!node)
    {
        array.Add( wxDataViewItem( (void*) m_root ) );
        return 1;
    }

    if (node->GetChildCount() == 0)
    {
        return 0;
    }

    unsigned int count = node->GetChildren().GetCount();
    for (unsigned int pos = 0; pos < count; pos++)
    {
        MyProjectTreeModelNode *child = node->GetChildren().Item( pos );
        array.Add( wxDataViewItem( (void*) child ) );
    }

    return count;
}

MyProjectTreeModelNode *  MyProjectTreeModel::SearchValue(MyProjectTreeModelNode *parent, const wxVariant &value, int level, int col)
{

    MyProjectTreeModelNodePtrArray node_array;
    if(!parent || parent == m_root)
        node_array = m_root->GetChildren();
    else node_array = parent->GetChildren();

    MyProjectTreeModelNodePtrArray::iterator iter;
    if(level == 1)
    {
        for(iter =  node_array.begin(); iter <= node_array.end(); iter++)
        {
            MyProjectTreeModelNode * temp = *iter;
            if(temp->m_index == value.GetString())
                return temp;
        }
    }

    if(level == 2)
    {
        for(iter =  node_array.begin(); iter <= node_array.end(); iter++)
        {
            MyProjectTreeModelNode * temp = *iter;
            switch(col)
            {
            case 1 :
                if(temp->m_wbs == value.GetString())
                    return temp;
                break;
            case 2:
                if(temp->m_lift_id == value.GetString())
                    return temp;
                break;
            case 3:
                if(temp->m_elevator_type == value.GetString())
                    return temp;
                break;
            case 4:
                if(temp->m_project_type == value.GetString())
                    return temp;
                break;
            case 5:
                if(temp->m_req_finish == value.GetString())
                    return temp;
                break;
            case 6:
                if(temp->m_res_person.Left(8) == value.GetString())
                    return temp;
                break;
            default:
                return NULL;
            }
        }
    }

    return NULL;

}

int  MyProjectTreeModel::HasContainer( const wxDataViewItem &item )
{
    MyProjectTreeModelNode *node = (MyProjectTreeModelNode*) item.GetID();

    if(!node)
    {
        return -1;
    }

    return (int) (node->GetChildCount());
}

bool MyProjectTreeModel::IsBlank()
{
    if (!m_root)
        return true;

    if(HasContainer(wxDataViewItem(m_root))>0)
        return false;

    return true;
}

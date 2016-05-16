#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif


#include "wfdataviewstore.h"
#include <wx/msgdlg.h>

wxDataViewTreeModel::wxDataViewTreeModel()
{
    //ctor
    wxString str = _("项目清单");
    m_root = new wfTreeModelNode(str);

}

wfTreeModelNode* wxDataViewTreeModel::AddToRoot(wxPostgreSQLresult *_res)
{
    if(!m_root)
    {
        wxString str = _("项目清单");
        m_root = new wfTreeModelNode(str);
    }

    wxASSERT(m_root);
    // add to the new node to the root;
    wfTreeModelNode *child_node =
        new wfTreeModelNode( m_root, _res,  1);
    m_root->Append( child_node );

    // notify control
    wxDataViewItem child( (void*) child_node );
    wxDataViewItem parent( (void*) m_root );
    ItemAdded( parent, child );

    return child_node;
}

void wxDataViewTreeModel::GetValue( wxVariant &variant,
                           const wxDataViewItem &item, unsigned int col ) const
{
    wxASSERT(item.IsOk());

    wfTreeModelNode *node = (wfTreeModelNode*) item.GetID();


     switch(col)
     {
     case 0:
          variant = node->m_wbs;
           break;
     case 1:
           variant = node->m_proj_name;
           break;
     case 2:
           variant = node->m_lift_no;
           break;
     case 3:
           if(node->m_level == 2)
              variant = node->m_elevator_type;
           break;
     case 4:
           if(node->m_level == 2)
               variant = node->m_proj_catalog;
           break;
     case 5:
          if(node->m_level == 2)
            variant = node->m_req_finish;
           break;
     case 6:
           if(node->m_level == 2)
             variant = node->m_proj_status;
           break;
     case 7:
           if(node->m_level == 2)
              variant = node->m_res;
           break;
     case 8:
          if(node->m_level == 2)
             variant = node->m_progress;
           break;
    default:
        wxMessageBox( _("MyProjectTreeModel::GetValue: wrong column %d")+NumToStr(col),_("错误"),wxOK );
     }
}

bool wxDataViewTreeModel::SetValue( const wxVariant &variant,
                        const wxDataViewItem &item, unsigned int col )
{
    wxASSERT(item.IsOk());

    wfTreeModelNode *node = (wfTreeModelNode*) item.GetID();

    switch(col)
    {
   case 0:
          node->m_wbs = variant.GetString();
          return true;
   case 1:
          node->m_proj_name = variant.GetString();
          return true;
   case 2:
          node->m_lift_no = variant.GetString();
          return true;
   case 3:
          if(node->m_level == 2)
             node->m_elevator_type = variant.GetString();
          return true;
   case 4:
          if(node->m_level == 2)
              node->m_proj_catalog = variant.GetString();
          return true;
   case 5:
          if(node->m_level == 2)
            node->m_req_finish = variant.GetString();
          return true;
   case 6:
          if(node->m_level == 2)
            node->m_proj_status = variant.GetString();
          return true;
   case 7:
          if(node->m_level == 2)
             node->m_res = variant.GetString();
          return true;
    case 8:
          if(node->m_level == 2)
             node->m_progress = variant.GetLong();
          return true;
    default:
        wxMessageBox( _("MyProjectTreeModel::GetValue: wrong column %d")+NumToStr(col),_("错误"),wxOK );
    }

    return false;
}


void wxDataViewTreeModel::AddToNode(wfTreeModelNode *_parent,  wxPostgreSQLresult *_res)
{
    wxASSERT(_parent);

    // add to the new node to the parent;
    wfTreeModelNode *child_node =
        new wfTreeModelNode( _parent, _res, 2);
    _parent->Append( child_node );

    // notify control
    wxDataViewItem child( (void*) child_node );
    wxDataViewItem parent( (void*) _parent );
    ItemAdded( parent, child );
}

void wxDataViewTreeModel::Delete( const wxDataViewItem &item )
{
   wfTreeModelNode *node = (wfTreeModelNode*) item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return;

    wxDataViewItem parent( node->GetParent() );
    if (!parent.IsOk())
    {
        wxASSERT(node == m_root);

        // don't make the control completely empty:
        wxMessageBox( _("根节点无法删除!" ),_("错误"),wxOK);
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

void wxDataViewTreeModel::DeleteAllItems()
{
    wxDataViewItemArray array_children;
    int i_count = GetChildren(wxDataViewItem((void *)m_root), array_children);

    for(int i=0;i<i_count; i++)
    {
        Delete(array_children.Item(i));
    }
}
/*
int wxDataViewTreeModel::Compare( const wxDataViewItem &item1, const wxDataViewItem &item2,
                 unsigned int column, bool ascending ) const
{
        wxASSERT(item1.IsOk() && item2.IsOk());
    // should never happen

    if (IsContainer(item1) && IsContainer(item2))
    {
        wxVariant value1, value2;
        GetValue( value1, item1, 0 );
        GetValue( value2, item2, 0 );

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
*/

/*
bool  wxDataViewTreeModel::GetAttr(const wxDataViewItem &item, unsigned int col,
                           wxDataViewItemAttr &attr) const
{

    wxASSERT(item.IsOk());

    wfTreeModelNode *node = (wfTreeModelNode*) item.GetID();

    attr = *(node->m_attr);
    return true;
}
*/
bool wxDataViewTreeModel::IsEnabled( const wxDataViewItem &item,
                            unsigned int col ) const
{
     wxASSERT(item.IsOk());

      return true;
}

wxDataViewItem wxDataViewTreeModel::GetParent( const wxDataViewItem &item ) const
{
        // the invisible root node has no parent
    if (!item.IsOk())
        return wxDataViewItem(0);

    wfTreeModelNode *node = (wfTreeModelNode*) item.GetID();

    if (node == m_root)
        return wxDataViewItem(0);

    return wxDataViewItem( (void*) node->GetParent() );
}

bool wxDataViewTreeModel::IsContainer( const wxDataViewItem &item ) const
{
    if (!item.IsOk())
        return false;

    wfTreeModelNode *node = (wfTreeModelNode*) item.GetID();
    return node->IsContainer();
}

unsigned int wxDataViewTreeModel::GetChildren( const wxDataViewItem &parent,
                                      wxDataViewItemArray &array ) const
{
    wfTreeModelNode *node = (wfTreeModelNode*) parent.GetID();
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
        wfTreeModelNode *child = node->GetChildren().Item( pos );
        array.Add( wxDataViewItem( (void*) child ) );
    }

    return count;
}

wfTreeModelNode* wxDataViewTreeModel::SearchValue(wfTreeModelNode *parent, const wxVariant &value, int level, int col)
{
    if(col>=GetColumnCount())
    {
        wxMessageBox( _("wxDataViewModel::SearchValue: wrong column %d")+NumToStr(col), _("错误"),wxOK );
        return NULL;
    }


    wfTreeModelNodePtrArray node_array;

    if(!parent || parent == m_root)
        node_array = m_root->GetChildren();
    else node_array = parent->GetChildren();

    wfTreeModelNodePtrArray::iterator iter;
    if(level == 1)
    {
        for(iter =  node_array.begin(); iter <= node_array.end(); iter++)
        {
            wfTreeModelNode * temp = *iter;

            switch(col)
            {
            case 0:
                 if(temp->m_wbs == value.GetString())
                    return temp;
                 break;
            case 1:
                 if(temp->m_proj_name == value.GetString())
                    return temp;
                 break;
            case 2:
                 if(temp->m_lift_no == value.GetString())
                    return temp;
                break;
            }
        }
    }

    if(level == 2)
    {
        for(iter =  node_array.begin(); iter <= node_array.end(); iter++)
        {
            wfTreeModelNode * temp = *iter;

            switch(col)
            {
            case 0:
                 if(temp->m_wbs == value.GetString())
                    return temp;
                 break;
            case 1:
                 if(temp->m_proj_name == value.GetString())
                    return temp;
                 break;
            case 2:
                 if(temp->m_lift_no == value.GetString())
                    return temp;
                break;
            case 3:
                 if(temp->m_elevator_type == value.GetString())
                    return temp;
                 break;
            case 4:
                  if(temp->m_proj_catalog == value.GetString())
                    return temp;
                  break;
            case 5:
                  if(temp->m_req_finish == value.GetString())
                    return temp;
                  break;
            case 6:
                  if(temp->m_proj_status == value.GetString())
                    return temp;
                  break;
            case 7:
                  if(temp->m_res == value.GetString())
                    return temp;
                  break;
            case 8:
                  if(temp->m_progress == value.GetLong())
                    return temp;
                  break;
            }

        }
    }

    return NULL;
}

int  wxDataViewTreeModel::GetChildrenCount( const wxDataViewItem &item )
{
    wfTreeModelNode *node = (wfTreeModelNode*) item.GetID();

    if(!node)
    {
        return -1;
    }

    return (int) (node->GetChildCount());
}

bool  wxDataViewTreeModel::IsBlank()
{
    if (!m_root)
        return true;

    if(GetChildrenCount(wxDataViewItem(m_root))>0)
        return false;

    return true;
}

int  wxDataViewTreeModel::HasContainer( const wxDataViewItem &item )
{
    wfTreeModelNode *node = (wfTreeModelNode*) item.GetID();

    if(!node)
    {
        return -1;
    }

    return (int) (node->GetChildCount());
}


int str_to_catalog(wxString str_catalog)
{
   if(str_catalog == wxT("Common Project"))
      return 1;

   if(str_catalog == wxT("High-Speed Project"))
       return 2;

   if(str_catalog == wxT("Special Project"))
       return 3;

   if(str_catalog == wxT("Major Project"))
       return 4;

   if(str_catalog == wxT("Pre_engineering"))
       return 5;

   if(str_catalog == wxT("Lean Project"))
       return 6;

   return -1;
}

wxString catalog_to_str(int i_catalog)
{
    switch(i_catalog)
    {
    case 1:
         return wxT("Common Project");
    case 2:
         return wxT("High-Speed Project");
    case 3:
         return wxT("Special Project");
    case 4:
         return wxT("Major Project");
    case 5:
         return wxT("Pre_engineering");
    case 6:
         return wxT("Lean Project");
    default:
         return wxT("Common Project");
    }

    return wxEmptyString;
}


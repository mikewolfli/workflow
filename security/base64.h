/*
 * This file is part of the Code::Blocks IDE and licensed under the GNU Lesser General Public License, version 3
 * http://www.gnu.org/licenses/lgpl-3.0.html
 */

#ifndef CB_BASE64_H
#define CB_BASE64_H

#include <wx/defs.h>
#include <wx/string.h>

namespace Base64
{
    wxString Encode(const wxUint8* pData, size_t len);
    wxString Encode(const wxString& data);
    wxString Decode(const wxString& data);
};

#endif // CB_BASE64_H

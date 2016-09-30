
#include "wxpg_utils.h"

// Conversions


wxString BoolToYesNo(bool value)
{
	return value ? _("Yes") : _("No");
}

wxString BoolToY(bool value)
{
    return value ? _("Y") : _("");
}


wxString BoolToStr(bool value)
{
	return value ? wxT("true") : wxT("false");
}



bool StrToBool(const wxString &value)
{
	if (value.StartsWith(wxT("t")))
	{
		return true;
	}
	else if (value.StartsWith(wxT("T")))
	{
		return true;
	}
	else if (value.StartsWith(wxT("1")))
	{
		return true;
	}
	else if (value.StartsWith(wxT("Y")))
	{
		return true;
	}
	else if (value.StartsWith(wxT("y")))
	{
		return true;
	}
	else if (value == wxT("on"))
		return true;

	return false;
}

wxString NumToStr(int value)
{
	wxString result;
	result.Printf(wxT("%d"), value);
	return result;
}

wxString NumToStr(long value)
{
	wxString result;
	result.Printf(wxT("%ld"), value);
	return result;
}


wxString NumToStr(wxOid value)
{
	wxString result;
	result.Printf(wxT("%lu"), (long)value);
	return result;
}


long StrToLong(const wxString &value)
{
	return atol(value.ToAscii());
}


int StrToInt(const wxString &value)
{
    return atoi(value.ToAscii());
}

wxOid StrToOid(const wxString &value)
{
	return (wxOid)strtoul(value.ToAscii(), 0, 10);
}

wxString generate_spaces(int length)
{
	return wxString().Pad(length);
}

wxString NumToStr(double value)
{
	wxString result;
	static wxString decsep;

	if (decsep.Length() == 0)
	{
		decsep.Printf(wxT("%lf"), 1.2);
		decsep = decsep[(unsigned int)1];
	}

	result.Printf(wxT("%lf"), value);
	result.Replace(decsep, wxT("."));

	// Get rid of excessive decimal places
	if (result.Contains(wxT(".")))
		while (result.Right(1) == wxT("0"))
			result.RemoveLast();
	if (result.Right(1) == wxT("."))
		result.RemoveLast();

	return result;
}


wxString NumToStr(wxLongLong value)
{
	wxString str;
#if wxCHECK_VERSION(3, 0, 0)
	str.Printf("%" wxLongLongFmtSpec "d", value.GetValue());
#else
	str.Printf(wxT("%") wxLongLongFmtSpec wxT("d"), value.GetValue());
#endif
	return str;
}


double StrToDouble(const wxString &value)
{
	wxCharBuffer buf = value.ToAscii();
	char *p = (char *)strchr(buf, '.');
	if (p)
		*p = localeconv()->decimal_point[0];

	return strtod(buf, 0);
}


wxLongLong StrToLongLong(const wxString &value)
{
	return atolonglong(value.ToAscii());
}


wxString DateToAnsiStr(const wxDateTime &datetime)
{
	if (!datetime.IsValid())
		return wxEmptyString;

	return datetime.FormatISODate() + wxT(" ") + datetime.FormatISOTime();
}

wxString DateToStrShort(const wxDateTime &datetime)
{
 	if (!datetime.IsValid())
		return wxEmptyString;

	return datetime.FormatISODate() + wxT(" ") + datetime.Format("%H:%M");
}

wxString DateToStrFormat(const wxDateTime &datetime)
{
	if (!datetime.IsValid())
		return wxEmptyString;

	return datetime.Format("%Y-%m-%d");
}

wxString DateToYearMonth(const wxDateTime &datetime)
{
	if (!datetime.IsValid())
		return wxEmptyString;

	return datetime.Format("%Y%m");
}

wxString DateToStr(const wxDateTime &datetime)
{
	if (!datetime.IsValid())
		return wxEmptyString;

	return datetime.FormatDate() + wxT(" ") + datetime.FormatTime();
}


wxDateTime StrToDateTime(const wxString &value)
{
	wxDateTime dt;
	/* This hasn't just been used. ( Is not infinity ) */
	if ( !value.IsEmpty() )
		dt.ParseDateTime(value);
	return dt;
}

wxDateTime StrToDate(const wxString &value)
{
	wxDateTime dt;
	/* This hasn't just been used. ( Is not infinity ) */
	if ( !value.IsEmpty() )
		dt.ParseDate(value);
	return dt;
}

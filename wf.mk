##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=wf
ConfigurationName      :=Release
WorkspacePath          := "D:\develop\code\workspace\wfcode\wf"
ProjectPath            := "D:\develop\code\workspace\wfcode\wf"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=10256603
Date                   :=28/10/2015
CodeLitePath           :="D:\tools\CodeLite"
LinkerName             :=D:/tools/CodeBlocks/build/MinGW/bin/g++.exe
SharedObjectLinkerName :=D:/tools/CodeBlocks/build/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=bin/Release/wf
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="wf.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=D:/tools/CodeBlocks/build/MinGW/bin/windres.exe
LinkOptions            :=  -s -mthreads 
IncludePath            := $(IncludeSwitch)$(CODEBLOCKS)/sdk/wx/include  $(IncludeSwitch). $(IncludeSwitch)$(CODEBLOCKS)/sdk/wx/lib/gcc_lib/mswu $(IncludeSwitch)$(CODEBLOCKS)/sdk/pugixml/src $(IncludeSwitch)interface $(IncludeSwitch)utils $(IncludeSwitch)thread $(IncludeSwitch)../wf $(IncludeSwitch)postgresql $(IncludeSwitch)interface $(IncludeSwitch)xlslib/src $(IncludeSwitch)pugixml/src $(IncludeSwitch)nwrfcsdk/include $(IncludeSwitch)qrencode $(IncludeSwitch)wxcurl/include $(IncludeSwitch)wxJson/include 
IncludePCH             := 
RcIncludePath          := $(IncludeSwitch)$(CODEBLOCKS)/sdk/wx/include $(IncludeSwitch)$(CODEBLOCKS)/sdk/wx/include 
Libs                   := $(LibrarySwitch)wxtoolbox $(LibrarySwitch)wxmsw31u $(LibrarySwitch)wxmsw31u_gl $(LibrarySwitch)wxpng $(LibrarySwitch)wxjpeg $(LibrarySwitch)wxregexu $(LibrarySwitch)wxexpat $(LibrarySwitch)wxscintilla $(LibrarySwitch)wxtiff $(LibrarySwitch)wxzlib $(LibrarySwitch)xlslib/lib/libxls $(LibrarySwitch)wxJson/lib/libwxjson $(LibrarySwitch)postgresql/gcc/libpq $(LibrarySwitch)nwrfcsdk/lib/sapnwrfc $(LibrarySwitch)nwrfcsdk/lib/libsapucum $(LibrarySwitch)nwrfcsdk/lib/sapdecfICUlib $(LibrarySwitch)curl $(LibrarySwitch)ws2_32 $(LibrarySwitch)wldap32 $(LibrarySwitch)ssl $(LibrarySwitch)crypto $(LibrarySwitch)ssh2 $(LibrarySwitch)z 
ArLibs                 :=  "libwxtoolbox.a" "libwxmsw31u.a" "libwxmsw31u_gl.a" "libwxpng.a" "libwxjpeg.a" "libwxregexu.a" "libwxexpat.a" "libwxscintilla.a" "libwxtiff.a" "libwxzlib.a" "xlslib/lib/libxls.a" "wxJson/lib/libwxjson.a" "postgresql/gcc/libpq.a" "nwrfcsdk/lib/sapnwrfc.a" "nwrfcsdk/lib/libsapucum.a" "nwrfcsdk/lib/sapdecfICUlib.a" "libcurl.a" "ws2_32" "wldap32" "libssl.a" "libcrypto.a" "libssh2.a" "libz.a" 
LibPath                :=$(LibraryPathSwitch)$(CODEBLOCKS)/sdk/wx/lib/gcc_lib  $(LibraryPathSwitch). $(LibraryPathSwitch)$(CODEBLOCKS)/sdk/wx/lib/gcc_lib $(LibraryPathSwitch)$(CODEBLOCKS)/sdk/pugixml/lib/gcc $(LibraryPathSwitch)wxJSON/lib/gcc_lib $(LibraryPathSwitch)postgresql/gcc $(LibraryPathSwitch)wxJson/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := D:/tools/CodeBlocks/build/MinGW/bin/ar.exe rcu
CXX      := D:/tools/CodeBlocks/build/MinGW/bin/g++.exe
CC       := D:/tools/CodeBlocks/build/MinGW/bin/gcc.exe
CXXFLAGS := -std=gnu++11 -O2 -DWIN32 -D__WXMSW__ -D_UNICODE -DNDEBUG -D_WINDOWS -DNOPCH -Wall -pipe -mthreads -D__GNUWIN32__ -D__WXMSW__ -DwxUSE_UNICODE -DSAPwithUNICODE -DHAVE_CONFIG_H -DCURL_STATICLIB  $(Preprocessors)
CFLAGS   :=  -O2 -DWIN32 -D__WXMSW__ -D_UNICODE -DNDEBUG -D_WINDOWS -DNOPCH -Wall -pipe -mthreads -D__GNUWIN32__ -D__WXMSW__ -DwxUSE_UNICODE -DSAPwithUNICODE -DHAVE_CONFIG_H -DCURL_STATICLIB  $(Preprocessors)
ASFLAGS  := 
AS       := D:/tools/CodeBlocks/build/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\tools\CodeLite
WXWIN:=D:\tools\CodeLite\wxlib
PATH:=$(WXWIN)\lib\gcc_dll;$(PATH)
WXCFG:=gcc_dll\mswu
UNIT_TEST_PP_SRC_DIR:=D:\tools\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/add_nstd_app_item.cpp$(ObjectSuffix) $(IntermediateDirectory)/cf_task_list.cpp$(ObjectSuffix) $(IntermediateDirectory)/communication_dlg.cpp$(ObjectSuffix) $(IntermediateDirectory)/configure_mat_list_editor.cpp$(ObjectSuffix) $(IntermediateDirectory)/connect_para_dlg.cpp$(ObjectSuffix) $(IntermediateDirectory)/contract_label_print.cpp$(ObjectSuffix) $(IntermediateDirectory)/contractlabeldraw.cpp$(ObjectSuffix) $(IntermediateDirectory)/ctrl_treelistctrl.cpp$(ObjectSuffix) $(IntermediateDirectory)/datepickerdlg.cpp$(ObjectSuffix) $(IntermediateDirectory)/enter_log.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/evaluate_dlg.cpp$(ObjectSuffix) $(IntermediateDirectory)/generated_id_display_panel.cpp$(ObjectSuffix) $(IntermediateDirectory)/info_id_generator_panel.cpp$(ObjectSuffix) $(IntermediateDirectory)/ins_nonstd_proc_log.cpp$(ObjectSuffix) $(IntermediateDirectory)/ins_proc_log.cpp$(ObjectSuffix) $(IntermediateDirectory)/instance_unit_info.cpp$(ObjectSuffix) $(IntermediateDirectory)/interface_ctlSQLGrid.cpp$(ObjectSuffix) $(IntermediateDirectory)/interface_nstdapptable.cpp$(ObjectSuffix) $(IntermediateDirectory)/interface_sqledittable.cpp$(ObjectSuffix) $(IntermediateDirectory)/interface_sqlresulttable.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/interface_wxPostgreSQL.cpp$(ObjectSuffix) $(IntermediateDirectory)/interface_wxpg_utils.cpp$(ObjectSuffix) $(IntermediateDirectory)/login_dlg.cpp$(ObjectSuffix) $(IntermediateDirectory)/mydatepicker.cpp$(ObjectSuffix) $(IntermediateDirectory)/ndo_generator_panel.cpp$(ObjectSuffix) $(IntermediateDirectory)/nstd_app_item_units.cpp$(ObjectSuffix) $(IntermediateDirectory)/nstd_app_search.cpp$(ObjectSuffix) $(IntermediateDirectory)/nstd_app_unit_list.cpp$(ObjectSuffix) $(IntermediateDirectory)/nstd_apply_panel.cpp$(ObjectSuffix) $(IntermediateDirectory)/nstd_author_panel.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/nstd_ins_doc.cpp$(ObjectSuffix) $(IntermediateDirectory)/nstd_mat_apply.cpp$(ObjectSuffix) $(IntermediateDirectory)/nstd_mat_muti_level_task_list.cpp$(ObjectSuffix) $(IntermediateDirectory)/nstd_mat_task_list.cpp$(ObjectSuffix) $(IntermediateDirectory)/nstd_reason_list.cpp$(ObjectSuffix) $(IntermediateDirectory)/nstd_task_author.cpp$(ObjectSuffix) $(IntermediateDirectory)/nstd_task_tree_list.cpp$(ObjectSuffix) $(IntermediateDirectory)/po_confirm_panel.cpp$(ObjectSuffix) $(IntermediateDirectory)/private_setting.cpp$(ObjectSuffix) $(IntermediateDirectory)/private_tasks_panel.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/prj_hex_result_dlg.cpp$(ObjectSuffix) $(IntermediateDirectory)/proj_configure_history.cpp$(ObjectSuffix) $(IntermediateDirectory)/project_author_panel.cpp$(ObjectSuffix) $(IntermediateDirectory)/project_info_panel.cpp$(ObjectSuffix) $(IntermediateDirectory)/project_review_author_panel.cpp$(ObjectSuffix) $(IntermediateDirectory)/project_review_panel.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_pugixml.cpp$(ObjectSuffix) $(IntermediateDirectory)/qrencode_bitstream.c$(ObjectSuffix) $(IntermediateDirectory)/qrencode_mask.c$(ObjectSuffix) $(IntermediateDirectory)/qrencode_mmask.c$(ObjectSuffix) \
	$(IntermediateDirectory)/qrencode_mqrspec.c$(ObjectSuffix) $(IntermediateDirectory)/qrencode_qrencode.c$(ObjectSuffix) $(IntermediateDirectory)/qrencode_qrinput.c$(ObjectSuffix) $(IntermediateDirectory)/qrencode_qrspec.c$(ObjectSuffix) $(IntermediateDirectory)/qrencode_rsecc.c$(ObjectSuffix) $(IntermediateDirectory)/qrencode_split.c$(ObjectSuffix) $(IntermediateDirectory)/reset_pwd.cpp$(ObjectSuffix) $(IntermediateDirectory)/return_log.cpp$(ObjectSuffix) $(IntermediateDirectory)/review_communication_log.cpp$(ObjectSuffix) $(IntermediateDirectory)/review_remarks_dlg.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/rfc_communication.cpp$(ObjectSuffix) $(IntermediateDirectory)/search_case.cpp$(ObjectSuffix) $(IntermediateDirectory)/security_base64.cpp$(ObjectSuffix) $(IntermediateDirectory)/security_md5.cpp$(ObjectSuffix) $(IntermediateDirectory)/security_wxMD5.cpp$(ObjectSuffix) $(IntermediateDirectory)/thread_curl_http.cpp$(ObjectSuffix) $(IntermediateDirectory)/thread_curl_thread.cpp$(ObjectSuffix) $(IntermediateDirectory)/thread_mythread.cpp$(ObjectSuffix) $(IntermediateDirectory)/unit_info_attach_dlg.cpp$(ObjectSuffix) $(IntermediateDirectory)/units_list_dlg.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/utils_wf_operator.cpp$(ObjectSuffix) $(IntermediateDirectory)/wfApp.cpp$(ObjectSuffix) $(IntermediateDirectory)/wfMain.cpp$(ObjectSuffix) $(IntermediateDirectory)/wf_listview_dlg.cpp$(ObjectSuffix) $(IntermediateDirectory)/wf_num_id_dlg.cpp$(ObjectSuffix) $(IntermediateDirectory)/wf_search.cpp$(ObjectSuffix) $(IntermediateDirectory)/wf_stdafx.cpp$(ObjectSuffix) $(IntermediateDirectory)/wf_workflow_panel.cpp$(ObjectSuffix) $(IntermediateDirectory)/workflow_wf.cpp$(ObjectSuffix) 

Objects1=$(IntermediateDirectory)/resource.rc$(ObjectSuffix) \
	



Objects=$(Objects0) $(Objects1) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	@echo $(Objects1) >> $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/add_nstd_app_item.cpp$(ObjectSuffix): add_nstd_app_item.cpp $(IntermediateDirectory)/add_nstd_app_item.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/add_nstd_app_item.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/add_nstd_app_item.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/add_nstd_app_item.cpp$(DependSuffix): add_nstd_app_item.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/add_nstd_app_item.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/add_nstd_app_item.cpp$(DependSuffix) -MM "add_nstd_app_item.cpp"

$(IntermediateDirectory)/add_nstd_app_item.cpp$(PreprocessSuffix): add_nstd_app_item.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/add_nstd_app_item.cpp$(PreprocessSuffix) "add_nstd_app_item.cpp"

$(IntermediateDirectory)/cf_task_list.cpp$(ObjectSuffix): cf_task_list.cpp $(IntermediateDirectory)/cf_task_list.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/cf_task_list.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cf_task_list.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cf_task_list.cpp$(DependSuffix): cf_task_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cf_task_list.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cf_task_list.cpp$(DependSuffix) -MM "cf_task_list.cpp"

$(IntermediateDirectory)/cf_task_list.cpp$(PreprocessSuffix): cf_task_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cf_task_list.cpp$(PreprocessSuffix) "cf_task_list.cpp"

$(IntermediateDirectory)/communication_dlg.cpp$(ObjectSuffix): communication_dlg.cpp $(IntermediateDirectory)/communication_dlg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/communication_dlg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/communication_dlg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/communication_dlg.cpp$(DependSuffix): communication_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/communication_dlg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/communication_dlg.cpp$(DependSuffix) -MM "communication_dlg.cpp"

$(IntermediateDirectory)/communication_dlg.cpp$(PreprocessSuffix): communication_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/communication_dlg.cpp$(PreprocessSuffix) "communication_dlg.cpp"

$(IntermediateDirectory)/configure_mat_list_editor.cpp$(ObjectSuffix): configure_mat_list_editor.cpp $(IntermediateDirectory)/configure_mat_list_editor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/configure_mat_list_editor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/configure_mat_list_editor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/configure_mat_list_editor.cpp$(DependSuffix): configure_mat_list_editor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/configure_mat_list_editor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/configure_mat_list_editor.cpp$(DependSuffix) -MM "configure_mat_list_editor.cpp"

$(IntermediateDirectory)/configure_mat_list_editor.cpp$(PreprocessSuffix): configure_mat_list_editor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/configure_mat_list_editor.cpp$(PreprocessSuffix) "configure_mat_list_editor.cpp"

$(IntermediateDirectory)/connect_para_dlg.cpp$(ObjectSuffix): connect_para_dlg.cpp $(IntermediateDirectory)/connect_para_dlg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/connect_para_dlg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/connect_para_dlg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/connect_para_dlg.cpp$(DependSuffix): connect_para_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/connect_para_dlg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/connect_para_dlg.cpp$(DependSuffix) -MM "connect_para_dlg.cpp"

$(IntermediateDirectory)/connect_para_dlg.cpp$(PreprocessSuffix): connect_para_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/connect_para_dlg.cpp$(PreprocessSuffix) "connect_para_dlg.cpp"

$(IntermediateDirectory)/contract_label_print.cpp$(ObjectSuffix): contract_label_print.cpp $(IntermediateDirectory)/contract_label_print.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/contract_label_print.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/contract_label_print.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/contract_label_print.cpp$(DependSuffix): contract_label_print.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/contract_label_print.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/contract_label_print.cpp$(DependSuffix) -MM "contract_label_print.cpp"

$(IntermediateDirectory)/contract_label_print.cpp$(PreprocessSuffix): contract_label_print.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/contract_label_print.cpp$(PreprocessSuffix) "contract_label_print.cpp"

$(IntermediateDirectory)/contractlabeldraw.cpp$(ObjectSuffix): contractlabeldraw.cpp $(IntermediateDirectory)/contractlabeldraw.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/contractlabeldraw.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/contractlabeldraw.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/contractlabeldraw.cpp$(DependSuffix): contractlabeldraw.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/contractlabeldraw.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/contractlabeldraw.cpp$(DependSuffix) -MM "contractlabeldraw.cpp"

$(IntermediateDirectory)/contractlabeldraw.cpp$(PreprocessSuffix): contractlabeldraw.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/contractlabeldraw.cpp$(PreprocessSuffix) "contractlabeldraw.cpp"

$(IntermediateDirectory)/ctrl_treelistctrl.cpp$(ObjectSuffix): ctrl/treelistctrl.cpp $(IntermediateDirectory)/ctrl_treelistctrl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/ctrl/treelistctrl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ctrl_treelistctrl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ctrl_treelistctrl.cpp$(DependSuffix): ctrl/treelistctrl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ctrl_treelistctrl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ctrl_treelistctrl.cpp$(DependSuffix) -MM "ctrl/treelistctrl.cpp"

$(IntermediateDirectory)/ctrl_treelistctrl.cpp$(PreprocessSuffix): ctrl/treelistctrl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ctrl_treelistctrl.cpp$(PreprocessSuffix) "ctrl/treelistctrl.cpp"

$(IntermediateDirectory)/datepickerdlg.cpp$(ObjectSuffix): datepickerdlg.cpp $(IntermediateDirectory)/datepickerdlg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/datepickerdlg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/datepickerdlg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/datepickerdlg.cpp$(DependSuffix): datepickerdlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/datepickerdlg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/datepickerdlg.cpp$(DependSuffix) -MM "datepickerdlg.cpp"

$(IntermediateDirectory)/datepickerdlg.cpp$(PreprocessSuffix): datepickerdlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/datepickerdlg.cpp$(PreprocessSuffix) "datepickerdlg.cpp"

$(IntermediateDirectory)/enter_log.cpp$(ObjectSuffix): enter_log.cpp $(IntermediateDirectory)/enter_log.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/enter_log.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/enter_log.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/enter_log.cpp$(DependSuffix): enter_log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/enter_log.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/enter_log.cpp$(DependSuffix) -MM "enter_log.cpp"

$(IntermediateDirectory)/enter_log.cpp$(PreprocessSuffix): enter_log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/enter_log.cpp$(PreprocessSuffix) "enter_log.cpp"

$(IntermediateDirectory)/evaluate_dlg.cpp$(ObjectSuffix): evaluate_dlg.cpp $(IntermediateDirectory)/evaluate_dlg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/evaluate_dlg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/evaluate_dlg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/evaluate_dlg.cpp$(DependSuffix): evaluate_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/evaluate_dlg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/evaluate_dlg.cpp$(DependSuffix) -MM "evaluate_dlg.cpp"

$(IntermediateDirectory)/evaluate_dlg.cpp$(PreprocessSuffix): evaluate_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/evaluate_dlg.cpp$(PreprocessSuffix) "evaluate_dlg.cpp"

$(IntermediateDirectory)/generated_id_display_panel.cpp$(ObjectSuffix): generated_id_display_panel.cpp $(IntermediateDirectory)/generated_id_display_panel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/generated_id_display_panel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/generated_id_display_panel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/generated_id_display_panel.cpp$(DependSuffix): generated_id_display_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/generated_id_display_panel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/generated_id_display_panel.cpp$(DependSuffix) -MM "generated_id_display_panel.cpp"

$(IntermediateDirectory)/generated_id_display_panel.cpp$(PreprocessSuffix): generated_id_display_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/generated_id_display_panel.cpp$(PreprocessSuffix) "generated_id_display_panel.cpp"

$(IntermediateDirectory)/info_id_generator_panel.cpp$(ObjectSuffix): info_id_generator_panel.cpp $(IntermediateDirectory)/info_id_generator_panel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/info_id_generator_panel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/info_id_generator_panel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/info_id_generator_panel.cpp$(DependSuffix): info_id_generator_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/info_id_generator_panel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/info_id_generator_panel.cpp$(DependSuffix) -MM "info_id_generator_panel.cpp"

$(IntermediateDirectory)/info_id_generator_panel.cpp$(PreprocessSuffix): info_id_generator_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/info_id_generator_panel.cpp$(PreprocessSuffix) "info_id_generator_panel.cpp"

$(IntermediateDirectory)/ins_nonstd_proc_log.cpp$(ObjectSuffix): ins_nonstd_proc_log.cpp $(IntermediateDirectory)/ins_nonstd_proc_log.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/ins_nonstd_proc_log.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ins_nonstd_proc_log.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ins_nonstd_proc_log.cpp$(DependSuffix): ins_nonstd_proc_log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ins_nonstd_proc_log.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ins_nonstd_proc_log.cpp$(DependSuffix) -MM "ins_nonstd_proc_log.cpp"

$(IntermediateDirectory)/ins_nonstd_proc_log.cpp$(PreprocessSuffix): ins_nonstd_proc_log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ins_nonstd_proc_log.cpp$(PreprocessSuffix) "ins_nonstd_proc_log.cpp"

$(IntermediateDirectory)/ins_proc_log.cpp$(ObjectSuffix): ins_proc_log.cpp $(IntermediateDirectory)/ins_proc_log.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/ins_proc_log.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ins_proc_log.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ins_proc_log.cpp$(DependSuffix): ins_proc_log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ins_proc_log.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ins_proc_log.cpp$(DependSuffix) -MM "ins_proc_log.cpp"

$(IntermediateDirectory)/ins_proc_log.cpp$(PreprocessSuffix): ins_proc_log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ins_proc_log.cpp$(PreprocessSuffix) "ins_proc_log.cpp"

$(IntermediateDirectory)/instance_unit_info.cpp$(ObjectSuffix): instance_unit_info.cpp $(IntermediateDirectory)/instance_unit_info.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/instance_unit_info.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/instance_unit_info.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/instance_unit_info.cpp$(DependSuffix): instance_unit_info.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/instance_unit_info.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/instance_unit_info.cpp$(DependSuffix) -MM "instance_unit_info.cpp"

$(IntermediateDirectory)/instance_unit_info.cpp$(PreprocessSuffix): instance_unit_info.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/instance_unit_info.cpp$(PreprocessSuffix) "instance_unit_info.cpp"

$(IntermediateDirectory)/interface_ctlSQLGrid.cpp$(ObjectSuffix): interface/ctlSQLGrid.cpp $(IntermediateDirectory)/interface_ctlSQLGrid.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/interface/ctlSQLGrid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/interface_ctlSQLGrid.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/interface_ctlSQLGrid.cpp$(DependSuffix): interface/ctlSQLGrid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/interface_ctlSQLGrid.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/interface_ctlSQLGrid.cpp$(DependSuffix) -MM "interface/ctlSQLGrid.cpp"

$(IntermediateDirectory)/interface_ctlSQLGrid.cpp$(PreprocessSuffix): interface/ctlSQLGrid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/interface_ctlSQLGrid.cpp$(PreprocessSuffix) "interface/ctlSQLGrid.cpp"

$(IntermediateDirectory)/interface_nstdapptable.cpp$(ObjectSuffix): interface/nstdapptable.cpp $(IntermediateDirectory)/interface_nstdapptable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/interface/nstdapptable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/interface_nstdapptable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/interface_nstdapptable.cpp$(DependSuffix): interface/nstdapptable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/interface_nstdapptable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/interface_nstdapptable.cpp$(DependSuffix) -MM "interface/nstdapptable.cpp"

$(IntermediateDirectory)/interface_nstdapptable.cpp$(PreprocessSuffix): interface/nstdapptable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/interface_nstdapptable.cpp$(PreprocessSuffix) "interface/nstdapptable.cpp"

$(IntermediateDirectory)/interface_sqledittable.cpp$(ObjectSuffix): interface/sqledittable.cpp $(IntermediateDirectory)/interface_sqledittable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/interface/sqledittable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/interface_sqledittable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/interface_sqledittable.cpp$(DependSuffix): interface/sqledittable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/interface_sqledittable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/interface_sqledittable.cpp$(DependSuffix) -MM "interface/sqledittable.cpp"

$(IntermediateDirectory)/interface_sqledittable.cpp$(PreprocessSuffix): interface/sqledittable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/interface_sqledittable.cpp$(PreprocessSuffix) "interface/sqledittable.cpp"

$(IntermediateDirectory)/interface_sqlresulttable.cpp$(ObjectSuffix): interface/sqlresulttable.cpp $(IntermediateDirectory)/interface_sqlresulttable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/interface/sqlresulttable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/interface_sqlresulttable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/interface_sqlresulttable.cpp$(DependSuffix): interface/sqlresulttable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/interface_sqlresulttable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/interface_sqlresulttable.cpp$(DependSuffix) -MM "interface/sqlresulttable.cpp"

$(IntermediateDirectory)/interface_sqlresulttable.cpp$(PreprocessSuffix): interface/sqlresulttable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/interface_sqlresulttable.cpp$(PreprocessSuffix) "interface/sqlresulttable.cpp"

$(IntermediateDirectory)/interface_wxPostgreSQL.cpp$(ObjectSuffix): interface/wxPostgreSQL.cpp $(IntermediateDirectory)/interface_wxPostgreSQL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/interface/wxPostgreSQL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/interface_wxPostgreSQL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/interface_wxPostgreSQL.cpp$(DependSuffix): interface/wxPostgreSQL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/interface_wxPostgreSQL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/interface_wxPostgreSQL.cpp$(DependSuffix) -MM "interface/wxPostgreSQL.cpp"

$(IntermediateDirectory)/interface_wxPostgreSQL.cpp$(PreprocessSuffix): interface/wxPostgreSQL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/interface_wxPostgreSQL.cpp$(PreprocessSuffix) "interface/wxPostgreSQL.cpp"

$(IntermediateDirectory)/interface_wxpg_utils.cpp$(ObjectSuffix): interface/wxpg_utils.cpp $(IntermediateDirectory)/interface_wxpg_utils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/interface/wxpg_utils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/interface_wxpg_utils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/interface_wxpg_utils.cpp$(DependSuffix): interface/wxpg_utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/interface_wxpg_utils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/interface_wxpg_utils.cpp$(DependSuffix) -MM "interface/wxpg_utils.cpp"

$(IntermediateDirectory)/interface_wxpg_utils.cpp$(PreprocessSuffix): interface/wxpg_utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/interface_wxpg_utils.cpp$(PreprocessSuffix) "interface/wxpg_utils.cpp"

$(IntermediateDirectory)/login_dlg.cpp$(ObjectSuffix): login_dlg.cpp $(IntermediateDirectory)/login_dlg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/login_dlg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/login_dlg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/login_dlg.cpp$(DependSuffix): login_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/login_dlg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/login_dlg.cpp$(DependSuffix) -MM "login_dlg.cpp"

$(IntermediateDirectory)/login_dlg.cpp$(PreprocessSuffix): login_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/login_dlg.cpp$(PreprocessSuffix) "login_dlg.cpp"

$(IntermediateDirectory)/mydatepicker.cpp$(ObjectSuffix): mydatepicker.cpp $(IntermediateDirectory)/mydatepicker.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/mydatepicker.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mydatepicker.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mydatepicker.cpp$(DependSuffix): mydatepicker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mydatepicker.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mydatepicker.cpp$(DependSuffix) -MM "mydatepicker.cpp"

$(IntermediateDirectory)/mydatepicker.cpp$(PreprocessSuffix): mydatepicker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mydatepicker.cpp$(PreprocessSuffix) "mydatepicker.cpp"

$(IntermediateDirectory)/ndo_generator_panel.cpp$(ObjectSuffix): ndo_generator_panel.cpp $(IntermediateDirectory)/ndo_generator_panel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/ndo_generator_panel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ndo_generator_panel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ndo_generator_panel.cpp$(DependSuffix): ndo_generator_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ndo_generator_panel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ndo_generator_panel.cpp$(DependSuffix) -MM "ndo_generator_panel.cpp"

$(IntermediateDirectory)/ndo_generator_panel.cpp$(PreprocessSuffix): ndo_generator_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ndo_generator_panel.cpp$(PreprocessSuffix) "ndo_generator_panel.cpp"

$(IntermediateDirectory)/nstd_app_item_units.cpp$(ObjectSuffix): nstd_app_item_units.cpp $(IntermediateDirectory)/nstd_app_item_units.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/nstd_app_item_units.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nstd_app_item_units.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nstd_app_item_units.cpp$(DependSuffix): nstd_app_item_units.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nstd_app_item_units.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nstd_app_item_units.cpp$(DependSuffix) -MM "nstd_app_item_units.cpp"

$(IntermediateDirectory)/nstd_app_item_units.cpp$(PreprocessSuffix): nstd_app_item_units.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nstd_app_item_units.cpp$(PreprocessSuffix) "nstd_app_item_units.cpp"

$(IntermediateDirectory)/nstd_app_search.cpp$(ObjectSuffix): nstd_app_search.cpp $(IntermediateDirectory)/nstd_app_search.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/nstd_app_search.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nstd_app_search.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nstd_app_search.cpp$(DependSuffix): nstd_app_search.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nstd_app_search.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nstd_app_search.cpp$(DependSuffix) -MM "nstd_app_search.cpp"

$(IntermediateDirectory)/nstd_app_search.cpp$(PreprocessSuffix): nstd_app_search.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nstd_app_search.cpp$(PreprocessSuffix) "nstd_app_search.cpp"

$(IntermediateDirectory)/nstd_app_unit_list.cpp$(ObjectSuffix): nstd_app_unit_list.cpp $(IntermediateDirectory)/nstd_app_unit_list.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/nstd_app_unit_list.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nstd_app_unit_list.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nstd_app_unit_list.cpp$(DependSuffix): nstd_app_unit_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nstd_app_unit_list.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nstd_app_unit_list.cpp$(DependSuffix) -MM "nstd_app_unit_list.cpp"

$(IntermediateDirectory)/nstd_app_unit_list.cpp$(PreprocessSuffix): nstd_app_unit_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nstd_app_unit_list.cpp$(PreprocessSuffix) "nstd_app_unit_list.cpp"

$(IntermediateDirectory)/nstd_apply_panel.cpp$(ObjectSuffix): nstd_apply_panel.cpp $(IntermediateDirectory)/nstd_apply_panel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/nstd_apply_panel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nstd_apply_panel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nstd_apply_panel.cpp$(DependSuffix): nstd_apply_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nstd_apply_panel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nstd_apply_panel.cpp$(DependSuffix) -MM "nstd_apply_panel.cpp"

$(IntermediateDirectory)/nstd_apply_panel.cpp$(PreprocessSuffix): nstd_apply_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nstd_apply_panel.cpp$(PreprocessSuffix) "nstd_apply_panel.cpp"

$(IntermediateDirectory)/nstd_author_panel.cpp$(ObjectSuffix): nstd_author_panel.cpp $(IntermediateDirectory)/nstd_author_panel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/nstd_author_panel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nstd_author_panel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nstd_author_panel.cpp$(DependSuffix): nstd_author_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nstd_author_panel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nstd_author_panel.cpp$(DependSuffix) -MM "nstd_author_panel.cpp"

$(IntermediateDirectory)/nstd_author_panel.cpp$(PreprocessSuffix): nstd_author_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nstd_author_panel.cpp$(PreprocessSuffix) "nstd_author_panel.cpp"

$(IntermediateDirectory)/nstd_ins_doc.cpp$(ObjectSuffix): nstd_ins_doc.cpp $(IntermediateDirectory)/nstd_ins_doc.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/nstd_ins_doc.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nstd_ins_doc.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nstd_ins_doc.cpp$(DependSuffix): nstd_ins_doc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nstd_ins_doc.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nstd_ins_doc.cpp$(DependSuffix) -MM "nstd_ins_doc.cpp"

$(IntermediateDirectory)/nstd_ins_doc.cpp$(PreprocessSuffix): nstd_ins_doc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nstd_ins_doc.cpp$(PreprocessSuffix) "nstd_ins_doc.cpp"

$(IntermediateDirectory)/nstd_mat_apply.cpp$(ObjectSuffix): nstd_mat_apply.cpp $(IntermediateDirectory)/nstd_mat_apply.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/nstd_mat_apply.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nstd_mat_apply.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nstd_mat_apply.cpp$(DependSuffix): nstd_mat_apply.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nstd_mat_apply.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nstd_mat_apply.cpp$(DependSuffix) -MM "nstd_mat_apply.cpp"

$(IntermediateDirectory)/nstd_mat_apply.cpp$(PreprocessSuffix): nstd_mat_apply.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nstd_mat_apply.cpp$(PreprocessSuffix) "nstd_mat_apply.cpp"

$(IntermediateDirectory)/nstd_mat_muti_level_task_list.cpp$(ObjectSuffix): nstd_mat_muti_level_task_list.cpp $(IntermediateDirectory)/nstd_mat_muti_level_task_list.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/nstd_mat_muti_level_task_list.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nstd_mat_muti_level_task_list.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nstd_mat_muti_level_task_list.cpp$(DependSuffix): nstd_mat_muti_level_task_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nstd_mat_muti_level_task_list.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nstd_mat_muti_level_task_list.cpp$(DependSuffix) -MM "nstd_mat_muti_level_task_list.cpp"

$(IntermediateDirectory)/nstd_mat_muti_level_task_list.cpp$(PreprocessSuffix): nstd_mat_muti_level_task_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nstd_mat_muti_level_task_list.cpp$(PreprocessSuffix) "nstd_mat_muti_level_task_list.cpp"

$(IntermediateDirectory)/nstd_mat_task_list.cpp$(ObjectSuffix): nstd_mat_task_list.cpp $(IntermediateDirectory)/nstd_mat_task_list.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/nstd_mat_task_list.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nstd_mat_task_list.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nstd_mat_task_list.cpp$(DependSuffix): nstd_mat_task_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nstd_mat_task_list.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nstd_mat_task_list.cpp$(DependSuffix) -MM "nstd_mat_task_list.cpp"

$(IntermediateDirectory)/nstd_mat_task_list.cpp$(PreprocessSuffix): nstd_mat_task_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nstd_mat_task_list.cpp$(PreprocessSuffix) "nstd_mat_task_list.cpp"

$(IntermediateDirectory)/nstd_reason_list.cpp$(ObjectSuffix): nstd_reason_list.cpp $(IntermediateDirectory)/nstd_reason_list.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/nstd_reason_list.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nstd_reason_list.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nstd_reason_list.cpp$(DependSuffix): nstd_reason_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nstd_reason_list.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nstd_reason_list.cpp$(DependSuffix) -MM "nstd_reason_list.cpp"

$(IntermediateDirectory)/nstd_reason_list.cpp$(PreprocessSuffix): nstd_reason_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nstd_reason_list.cpp$(PreprocessSuffix) "nstd_reason_list.cpp"

$(IntermediateDirectory)/nstd_task_author.cpp$(ObjectSuffix): nstd_task_author.cpp $(IntermediateDirectory)/nstd_task_author.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/nstd_task_author.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nstd_task_author.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nstd_task_author.cpp$(DependSuffix): nstd_task_author.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nstd_task_author.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nstd_task_author.cpp$(DependSuffix) -MM "nstd_task_author.cpp"

$(IntermediateDirectory)/nstd_task_author.cpp$(PreprocessSuffix): nstd_task_author.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nstd_task_author.cpp$(PreprocessSuffix) "nstd_task_author.cpp"

$(IntermediateDirectory)/nstd_task_tree_list.cpp$(ObjectSuffix): nstd_task_tree_list.cpp $(IntermediateDirectory)/nstd_task_tree_list.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/nstd_task_tree_list.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nstd_task_tree_list.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nstd_task_tree_list.cpp$(DependSuffix): nstd_task_tree_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nstd_task_tree_list.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nstd_task_tree_list.cpp$(DependSuffix) -MM "nstd_task_tree_list.cpp"

$(IntermediateDirectory)/nstd_task_tree_list.cpp$(PreprocessSuffix): nstd_task_tree_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nstd_task_tree_list.cpp$(PreprocessSuffix) "nstd_task_tree_list.cpp"

$(IntermediateDirectory)/po_confirm_panel.cpp$(ObjectSuffix): po_confirm_panel.cpp $(IntermediateDirectory)/po_confirm_panel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/po_confirm_panel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/po_confirm_panel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/po_confirm_panel.cpp$(DependSuffix): po_confirm_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/po_confirm_panel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/po_confirm_panel.cpp$(DependSuffix) -MM "po_confirm_panel.cpp"

$(IntermediateDirectory)/po_confirm_panel.cpp$(PreprocessSuffix): po_confirm_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/po_confirm_panel.cpp$(PreprocessSuffix) "po_confirm_panel.cpp"

$(IntermediateDirectory)/private_setting.cpp$(ObjectSuffix): private_setting.cpp $(IntermediateDirectory)/private_setting.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/private_setting.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/private_setting.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/private_setting.cpp$(DependSuffix): private_setting.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/private_setting.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/private_setting.cpp$(DependSuffix) -MM "private_setting.cpp"

$(IntermediateDirectory)/private_setting.cpp$(PreprocessSuffix): private_setting.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/private_setting.cpp$(PreprocessSuffix) "private_setting.cpp"

$(IntermediateDirectory)/private_tasks_panel.cpp$(ObjectSuffix): private_tasks_panel.cpp $(IntermediateDirectory)/private_tasks_panel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/private_tasks_panel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/private_tasks_panel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/private_tasks_panel.cpp$(DependSuffix): private_tasks_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/private_tasks_panel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/private_tasks_panel.cpp$(DependSuffix) -MM "private_tasks_panel.cpp"

$(IntermediateDirectory)/private_tasks_panel.cpp$(PreprocessSuffix): private_tasks_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/private_tasks_panel.cpp$(PreprocessSuffix) "private_tasks_panel.cpp"

$(IntermediateDirectory)/prj_hex_result_dlg.cpp$(ObjectSuffix): prj_hex_result_dlg.cpp $(IntermediateDirectory)/prj_hex_result_dlg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/prj_hex_result_dlg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/prj_hex_result_dlg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/prj_hex_result_dlg.cpp$(DependSuffix): prj_hex_result_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/prj_hex_result_dlg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/prj_hex_result_dlg.cpp$(DependSuffix) -MM "prj_hex_result_dlg.cpp"

$(IntermediateDirectory)/prj_hex_result_dlg.cpp$(PreprocessSuffix): prj_hex_result_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/prj_hex_result_dlg.cpp$(PreprocessSuffix) "prj_hex_result_dlg.cpp"

$(IntermediateDirectory)/proj_configure_history.cpp$(ObjectSuffix): proj_configure_history.cpp $(IntermediateDirectory)/proj_configure_history.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/proj_configure_history.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/proj_configure_history.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/proj_configure_history.cpp$(DependSuffix): proj_configure_history.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/proj_configure_history.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/proj_configure_history.cpp$(DependSuffix) -MM "proj_configure_history.cpp"

$(IntermediateDirectory)/proj_configure_history.cpp$(PreprocessSuffix): proj_configure_history.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/proj_configure_history.cpp$(PreprocessSuffix) "proj_configure_history.cpp"

$(IntermediateDirectory)/project_author_panel.cpp$(ObjectSuffix): project_author_panel.cpp $(IntermediateDirectory)/project_author_panel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/project_author_panel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/project_author_panel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/project_author_panel.cpp$(DependSuffix): project_author_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/project_author_panel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/project_author_panel.cpp$(DependSuffix) -MM "project_author_panel.cpp"

$(IntermediateDirectory)/project_author_panel.cpp$(PreprocessSuffix): project_author_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/project_author_panel.cpp$(PreprocessSuffix) "project_author_panel.cpp"

$(IntermediateDirectory)/project_info_panel.cpp$(ObjectSuffix): project_info_panel.cpp $(IntermediateDirectory)/project_info_panel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/project_info_panel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/project_info_panel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/project_info_panel.cpp$(DependSuffix): project_info_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/project_info_panel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/project_info_panel.cpp$(DependSuffix) -MM "project_info_panel.cpp"

$(IntermediateDirectory)/project_info_panel.cpp$(PreprocessSuffix): project_info_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/project_info_panel.cpp$(PreprocessSuffix) "project_info_panel.cpp"

$(IntermediateDirectory)/project_review_author_panel.cpp$(ObjectSuffix): project_review_author_panel.cpp $(IntermediateDirectory)/project_review_author_panel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/project_review_author_panel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/project_review_author_panel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/project_review_author_panel.cpp$(DependSuffix): project_review_author_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/project_review_author_panel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/project_review_author_panel.cpp$(DependSuffix) -MM "project_review_author_panel.cpp"

$(IntermediateDirectory)/project_review_author_panel.cpp$(PreprocessSuffix): project_review_author_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/project_review_author_panel.cpp$(PreprocessSuffix) "project_review_author_panel.cpp"

$(IntermediateDirectory)/project_review_panel.cpp$(ObjectSuffix): project_review_panel.cpp $(IntermediateDirectory)/project_review_panel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/project_review_panel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/project_review_panel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/project_review_panel.cpp$(DependSuffix): project_review_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/project_review_panel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/project_review_panel.cpp$(DependSuffix) -MM "project_review_panel.cpp"

$(IntermediateDirectory)/project_review_panel.cpp$(PreprocessSuffix): project_review_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/project_review_panel.cpp$(PreprocessSuffix) "project_review_panel.cpp"

$(IntermediateDirectory)/src_pugixml.cpp$(ObjectSuffix): pugixml/src/pugixml.cpp $(IntermediateDirectory)/src_pugixml.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/pugixml/src/pugixml.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_pugixml.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_pugixml.cpp$(DependSuffix): pugixml/src/pugixml.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_pugixml.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_pugixml.cpp$(DependSuffix) -MM "pugixml/src/pugixml.cpp"

$(IntermediateDirectory)/src_pugixml.cpp$(PreprocessSuffix): pugixml/src/pugixml.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_pugixml.cpp$(PreprocessSuffix) "pugixml/src/pugixml.cpp"

$(IntermediateDirectory)/qrencode_bitstream.c$(ObjectSuffix): qrencode/bitstream.c $(IntermediateDirectory)/qrencode_bitstream.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/qrencode/bitstream.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qrencode_bitstream.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qrencode_bitstream.c$(DependSuffix): qrencode/bitstream.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qrencode_bitstream.c$(ObjectSuffix) -MF$(IntermediateDirectory)/qrencode_bitstream.c$(DependSuffix) -MM "qrencode/bitstream.c"

$(IntermediateDirectory)/qrencode_bitstream.c$(PreprocessSuffix): qrencode/bitstream.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qrencode_bitstream.c$(PreprocessSuffix) "qrencode/bitstream.c"

$(IntermediateDirectory)/qrencode_mask.c$(ObjectSuffix): qrencode/mask.c $(IntermediateDirectory)/qrencode_mask.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/qrencode/mask.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qrencode_mask.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qrencode_mask.c$(DependSuffix): qrencode/mask.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qrencode_mask.c$(ObjectSuffix) -MF$(IntermediateDirectory)/qrencode_mask.c$(DependSuffix) -MM "qrencode/mask.c"

$(IntermediateDirectory)/qrencode_mask.c$(PreprocessSuffix): qrencode/mask.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qrencode_mask.c$(PreprocessSuffix) "qrencode/mask.c"

$(IntermediateDirectory)/qrencode_mmask.c$(ObjectSuffix): qrencode/mmask.c $(IntermediateDirectory)/qrencode_mmask.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/qrencode/mmask.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qrencode_mmask.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qrencode_mmask.c$(DependSuffix): qrencode/mmask.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qrencode_mmask.c$(ObjectSuffix) -MF$(IntermediateDirectory)/qrencode_mmask.c$(DependSuffix) -MM "qrencode/mmask.c"

$(IntermediateDirectory)/qrencode_mmask.c$(PreprocessSuffix): qrencode/mmask.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qrencode_mmask.c$(PreprocessSuffix) "qrencode/mmask.c"

$(IntermediateDirectory)/qrencode_mqrspec.c$(ObjectSuffix): qrencode/mqrspec.c $(IntermediateDirectory)/qrencode_mqrspec.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/qrencode/mqrspec.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qrencode_mqrspec.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qrencode_mqrspec.c$(DependSuffix): qrencode/mqrspec.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qrencode_mqrspec.c$(ObjectSuffix) -MF$(IntermediateDirectory)/qrencode_mqrspec.c$(DependSuffix) -MM "qrencode/mqrspec.c"

$(IntermediateDirectory)/qrencode_mqrspec.c$(PreprocessSuffix): qrencode/mqrspec.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qrencode_mqrspec.c$(PreprocessSuffix) "qrencode/mqrspec.c"

$(IntermediateDirectory)/qrencode_qrencode.c$(ObjectSuffix): qrencode/qrencode.c $(IntermediateDirectory)/qrencode_qrencode.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/qrencode/qrencode.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qrencode_qrencode.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qrencode_qrencode.c$(DependSuffix): qrencode/qrencode.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qrencode_qrencode.c$(ObjectSuffix) -MF$(IntermediateDirectory)/qrencode_qrencode.c$(DependSuffix) -MM "qrencode/qrencode.c"

$(IntermediateDirectory)/qrencode_qrencode.c$(PreprocessSuffix): qrencode/qrencode.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qrencode_qrencode.c$(PreprocessSuffix) "qrencode/qrencode.c"

$(IntermediateDirectory)/qrencode_qrinput.c$(ObjectSuffix): qrencode/qrinput.c $(IntermediateDirectory)/qrencode_qrinput.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/qrencode/qrinput.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qrencode_qrinput.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qrencode_qrinput.c$(DependSuffix): qrencode/qrinput.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qrencode_qrinput.c$(ObjectSuffix) -MF$(IntermediateDirectory)/qrencode_qrinput.c$(DependSuffix) -MM "qrencode/qrinput.c"

$(IntermediateDirectory)/qrencode_qrinput.c$(PreprocessSuffix): qrencode/qrinput.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qrencode_qrinput.c$(PreprocessSuffix) "qrencode/qrinput.c"

$(IntermediateDirectory)/qrencode_qrspec.c$(ObjectSuffix): qrencode/qrspec.c $(IntermediateDirectory)/qrencode_qrspec.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/qrencode/qrspec.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qrencode_qrspec.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qrencode_qrspec.c$(DependSuffix): qrencode/qrspec.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qrencode_qrspec.c$(ObjectSuffix) -MF$(IntermediateDirectory)/qrencode_qrspec.c$(DependSuffix) -MM "qrencode/qrspec.c"

$(IntermediateDirectory)/qrencode_qrspec.c$(PreprocessSuffix): qrencode/qrspec.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qrencode_qrspec.c$(PreprocessSuffix) "qrencode/qrspec.c"

$(IntermediateDirectory)/qrencode_rsecc.c$(ObjectSuffix): qrencode/rsecc.c $(IntermediateDirectory)/qrencode_rsecc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/qrencode/rsecc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qrencode_rsecc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qrencode_rsecc.c$(DependSuffix): qrencode/rsecc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qrencode_rsecc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/qrencode_rsecc.c$(DependSuffix) -MM "qrencode/rsecc.c"

$(IntermediateDirectory)/qrencode_rsecc.c$(PreprocessSuffix): qrencode/rsecc.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qrencode_rsecc.c$(PreprocessSuffix) "qrencode/rsecc.c"

$(IntermediateDirectory)/qrencode_split.c$(ObjectSuffix): qrencode/split.c $(IntermediateDirectory)/qrencode_split.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/qrencode/split.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qrencode_split.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qrencode_split.c$(DependSuffix): qrencode/split.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qrencode_split.c$(ObjectSuffix) -MF$(IntermediateDirectory)/qrencode_split.c$(DependSuffix) -MM "qrencode/split.c"

$(IntermediateDirectory)/qrencode_split.c$(PreprocessSuffix): qrencode/split.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qrencode_split.c$(PreprocessSuffix) "qrencode/split.c"

$(IntermediateDirectory)/reset_pwd.cpp$(ObjectSuffix): reset_pwd.cpp $(IntermediateDirectory)/reset_pwd.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/reset_pwd.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/reset_pwd.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/reset_pwd.cpp$(DependSuffix): reset_pwd.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/reset_pwd.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/reset_pwd.cpp$(DependSuffix) -MM "reset_pwd.cpp"

$(IntermediateDirectory)/reset_pwd.cpp$(PreprocessSuffix): reset_pwd.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/reset_pwd.cpp$(PreprocessSuffix) "reset_pwd.cpp"

$(IntermediateDirectory)/return_log.cpp$(ObjectSuffix): return_log.cpp $(IntermediateDirectory)/return_log.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/return_log.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/return_log.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/return_log.cpp$(DependSuffix): return_log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/return_log.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/return_log.cpp$(DependSuffix) -MM "return_log.cpp"

$(IntermediateDirectory)/return_log.cpp$(PreprocessSuffix): return_log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/return_log.cpp$(PreprocessSuffix) "return_log.cpp"

$(IntermediateDirectory)/review_communication_log.cpp$(ObjectSuffix): review_communication_log.cpp $(IntermediateDirectory)/review_communication_log.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/review_communication_log.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/review_communication_log.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/review_communication_log.cpp$(DependSuffix): review_communication_log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/review_communication_log.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/review_communication_log.cpp$(DependSuffix) -MM "review_communication_log.cpp"

$(IntermediateDirectory)/review_communication_log.cpp$(PreprocessSuffix): review_communication_log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/review_communication_log.cpp$(PreprocessSuffix) "review_communication_log.cpp"

$(IntermediateDirectory)/review_remarks_dlg.cpp$(ObjectSuffix): review_remarks_dlg.cpp $(IntermediateDirectory)/review_remarks_dlg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/review_remarks_dlg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/review_remarks_dlg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/review_remarks_dlg.cpp$(DependSuffix): review_remarks_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/review_remarks_dlg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/review_remarks_dlg.cpp$(DependSuffix) -MM "review_remarks_dlg.cpp"

$(IntermediateDirectory)/review_remarks_dlg.cpp$(PreprocessSuffix): review_remarks_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/review_remarks_dlg.cpp$(PreprocessSuffix) "review_remarks_dlg.cpp"

$(IntermediateDirectory)/rfc_communication.cpp$(ObjectSuffix): rfc_communication.cpp $(IntermediateDirectory)/rfc_communication.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/rfc_communication.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/rfc_communication.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/rfc_communication.cpp$(DependSuffix): rfc_communication.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/rfc_communication.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/rfc_communication.cpp$(DependSuffix) -MM "rfc_communication.cpp"

$(IntermediateDirectory)/rfc_communication.cpp$(PreprocessSuffix): rfc_communication.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/rfc_communication.cpp$(PreprocessSuffix) "rfc_communication.cpp"

$(IntermediateDirectory)/search_case.cpp$(ObjectSuffix): search_case.cpp $(IntermediateDirectory)/search_case.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/search_case.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/search_case.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/search_case.cpp$(DependSuffix): search_case.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/search_case.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/search_case.cpp$(DependSuffix) -MM "search_case.cpp"

$(IntermediateDirectory)/search_case.cpp$(PreprocessSuffix): search_case.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/search_case.cpp$(PreprocessSuffix) "search_case.cpp"

$(IntermediateDirectory)/security_base64.cpp$(ObjectSuffix): security/base64.cpp $(IntermediateDirectory)/security_base64.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/security/base64.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/security_base64.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/security_base64.cpp$(DependSuffix): security/base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/security_base64.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/security_base64.cpp$(DependSuffix) -MM "security/base64.cpp"

$(IntermediateDirectory)/security_base64.cpp$(PreprocessSuffix): security/base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/security_base64.cpp$(PreprocessSuffix) "security/base64.cpp"

$(IntermediateDirectory)/security_md5.cpp$(ObjectSuffix): security/md5.cpp $(IntermediateDirectory)/security_md5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/security/md5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/security_md5.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/security_md5.cpp$(DependSuffix): security/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/security_md5.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/security_md5.cpp$(DependSuffix) -MM "security/md5.cpp"

$(IntermediateDirectory)/security_md5.cpp$(PreprocessSuffix): security/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/security_md5.cpp$(PreprocessSuffix) "security/md5.cpp"

$(IntermediateDirectory)/security_wxMD5.cpp$(ObjectSuffix): security/wxMD5.cpp $(IntermediateDirectory)/security_wxMD5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/security/wxMD5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/security_wxMD5.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/security_wxMD5.cpp$(DependSuffix): security/wxMD5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/security_wxMD5.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/security_wxMD5.cpp$(DependSuffix) -MM "security/wxMD5.cpp"

$(IntermediateDirectory)/security_wxMD5.cpp$(PreprocessSuffix): security/wxMD5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/security_wxMD5.cpp$(PreprocessSuffix) "security/wxMD5.cpp"

$(IntermediateDirectory)/thread_curl_http.cpp$(ObjectSuffix): thread/curl_http.cpp $(IntermediateDirectory)/thread_curl_http.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/thread/curl_http.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/thread_curl_http.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/thread_curl_http.cpp$(DependSuffix): thread/curl_http.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/thread_curl_http.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/thread_curl_http.cpp$(DependSuffix) -MM "thread/curl_http.cpp"

$(IntermediateDirectory)/thread_curl_http.cpp$(PreprocessSuffix): thread/curl_http.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/thread_curl_http.cpp$(PreprocessSuffix) "thread/curl_http.cpp"

$(IntermediateDirectory)/thread_curl_thread.cpp$(ObjectSuffix): thread/curl_thread.cpp $(IntermediateDirectory)/thread_curl_thread.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/thread/curl_thread.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/thread_curl_thread.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/thread_curl_thread.cpp$(DependSuffix): thread/curl_thread.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/thread_curl_thread.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/thread_curl_thread.cpp$(DependSuffix) -MM "thread/curl_thread.cpp"

$(IntermediateDirectory)/thread_curl_thread.cpp$(PreprocessSuffix): thread/curl_thread.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/thread_curl_thread.cpp$(PreprocessSuffix) "thread/curl_thread.cpp"

$(IntermediateDirectory)/thread_mythread.cpp$(ObjectSuffix): thread/mythread.cpp $(IntermediateDirectory)/thread_mythread.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/thread/mythread.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/thread_mythread.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/thread_mythread.cpp$(DependSuffix): thread/mythread.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/thread_mythread.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/thread_mythread.cpp$(DependSuffix) -MM "thread/mythread.cpp"

$(IntermediateDirectory)/thread_mythread.cpp$(PreprocessSuffix): thread/mythread.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/thread_mythread.cpp$(PreprocessSuffix) "thread/mythread.cpp"

$(IntermediateDirectory)/unit_info_attach_dlg.cpp$(ObjectSuffix): unit_info_attach_dlg.cpp $(IntermediateDirectory)/unit_info_attach_dlg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/unit_info_attach_dlg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/unit_info_attach_dlg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/unit_info_attach_dlg.cpp$(DependSuffix): unit_info_attach_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/unit_info_attach_dlg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/unit_info_attach_dlg.cpp$(DependSuffix) -MM "unit_info_attach_dlg.cpp"

$(IntermediateDirectory)/unit_info_attach_dlg.cpp$(PreprocessSuffix): unit_info_attach_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/unit_info_attach_dlg.cpp$(PreprocessSuffix) "unit_info_attach_dlg.cpp"

$(IntermediateDirectory)/units_list_dlg.cpp$(ObjectSuffix): units_list_dlg.cpp $(IntermediateDirectory)/units_list_dlg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/units_list_dlg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/units_list_dlg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/units_list_dlg.cpp$(DependSuffix): units_list_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/units_list_dlg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/units_list_dlg.cpp$(DependSuffix) -MM "units_list_dlg.cpp"

$(IntermediateDirectory)/units_list_dlg.cpp$(PreprocessSuffix): units_list_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/units_list_dlg.cpp$(PreprocessSuffix) "units_list_dlg.cpp"

$(IntermediateDirectory)/utils_wf_operator.cpp$(ObjectSuffix): utils/wf_operator.cpp $(IntermediateDirectory)/utils_wf_operator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/utils/wf_operator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils_wf_operator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils_wf_operator.cpp$(DependSuffix): utils/wf_operator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils_wf_operator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/utils_wf_operator.cpp$(DependSuffix) -MM "utils/wf_operator.cpp"

$(IntermediateDirectory)/utils_wf_operator.cpp$(PreprocessSuffix): utils/wf_operator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils_wf_operator.cpp$(PreprocessSuffix) "utils/wf_operator.cpp"

$(IntermediateDirectory)/wfApp.cpp$(ObjectSuffix): wfApp.cpp $(IntermediateDirectory)/wfApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/wfApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wfApp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wfApp.cpp$(DependSuffix): wfApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wfApp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wfApp.cpp$(DependSuffix) -MM "wfApp.cpp"

$(IntermediateDirectory)/wfApp.cpp$(PreprocessSuffix): wfApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wfApp.cpp$(PreprocessSuffix) "wfApp.cpp"

$(IntermediateDirectory)/wfMain.cpp$(ObjectSuffix): wfMain.cpp $(IntermediateDirectory)/wfMain.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/wfMain.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wfMain.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wfMain.cpp$(DependSuffix): wfMain.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wfMain.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wfMain.cpp$(DependSuffix) -MM "wfMain.cpp"

$(IntermediateDirectory)/wfMain.cpp$(PreprocessSuffix): wfMain.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wfMain.cpp$(PreprocessSuffix) "wfMain.cpp"

$(IntermediateDirectory)/wf_listview_dlg.cpp$(ObjectSuffix): wf_listview_dlg.cpp $(IntermediateDirectory)/wf_listview_dlg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/wf_listview_dlg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wf_listview_dlg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wf_listview_dlg.cpp$(DependSuffix): wf_listview_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wf_listview_dlg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wf_listview_dlg.cpp$(DependSuffix) -MM "wf_listview_dlg.cpp"

$(IntermediateDirectory)/wf_listview_dlg.cpp$(PreprocessSuffix): wf_listview_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wf_listview_dlg.cpp$(PreprocessSuffix) "wf_listview_dlg.cpp"

$(IntermediateDirectory)/wf_num_id_dlg.cpp$(ObjectSuffix): wf_num_id_dlg.cpp $(IntermediateDirectory)/wf_num_id_dlg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/wf_num_id_dlg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wf_num_id_dlg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wf_num_id_dlg.cpp$(DependSuffix): wf_num_id_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wf_num_id_dlg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wf_num_id_dlg.cpp$(DependSuffix) -MM "wf_num_id_dlg.cpp"

$(IntermediateDirectory)/wf_num_id_dlg.cpp$(PreprocessSuffix): wf_num_id_dlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wf_num_id_dlg.cpp$(PreprocessSuffix) "wf_num_id_dlg.cpp"

$(IntermediateDirectory)/wf_search.cpp$(ObjectSuffix): wf_search.cpp $(IntermediateDirectory)/wf_search.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/wf_search.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wf_search.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wf_search.cpp$(DependSuffix): wf_search.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wf_search.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wf_search.cpp$(DependSuffix) -MM "wf_search.cpp"

$(IntermediateDirectory)/wf_search.cpp$(PreprocessSuffix): wf_search.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wf_search.cpp$(PreprocessSuffix) "wf_search.cpp"

$(IntermediateDirectory)/wf_stdafx.cpp$(ObjectSuffix): wf_stdafx.cpp $(IntermediateDirectory)/wf_stdafx.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/wf_stdafx.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wf_stdafx.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wf_stdafx.cpp$(DependSuffix): wf_stdafx.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wf_stdafx.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wf_stdafx.cpp$(DependSuffix) -MM "wf_stdafx.cpp"

$(IntermediateDirectory)/wf_stdafx.cpp$(PreprocessSuffix): wf_stdafx.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wf_stdafx.cpp$(PreprocessSuffix) "wf_stdafx.cpp"

$(IntermediateDirectory)/wf_workflow_panel.cpp$(ObjectSuffix): wf_workflow_panel.cpp $(IntermediateDirectory)/wf_workflow_panel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/wf_workflow_panel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wf_workflow_panel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wf_workflow_panel.cpp$(DependSuffix): wf_workflow_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wf_workflow_panel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wf_workflow_panel.cpp$(DependSuffix) -MM "wf_workflow_panel.cpp"

$(IntermediateDirectory)/wf_workflow_panel.cpp$(PreprocessSuffix): wf_workflow_panel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wf_workflow_panel.cpp$(PreprocessSuffix) "wf_workflow_panel.cpp"

$(IntermediateDirectory)/workflow_wf.cpp$(ObjectSuffix): workflow_wf.cpp $(IntermediateDirectory)/workflow_wf.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/develop/code/workspace/wfcode/wf/workflow_wf.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/workflow_wf.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/workflow_wf.cpp$(DependSuffix): workflow_wf.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/workflow_wf.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/workflow_wf.cpp$(DependSuffix) -MM "workflow_wf.cpp"

$(IntermediateDirectory)/workflow_wf.cpp$(PreprocessSuffix): workflow_wf.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/workflow_wf.cpp$(PreprocessSuffix) "workflow_wf.cpp"

$(IntermediateDirectory)/resource.rc$(ObjectSuffix): resource.rc
	$(RcCompilerName) -i "D:/develop/code/workspace/wfcode/wf/resource.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/resource.rc$(ObjectSuffix) $(RcIncludePath)

-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



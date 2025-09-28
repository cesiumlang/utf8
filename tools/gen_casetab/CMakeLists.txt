add_executable(gen_casetab gen_casetab.cpp)
set_property(TARGET gen_casetab PROPERTY CXX_STANDARD 20)
add_custom_command(
  OUTPUT ${PROJECT_SOURCE_DIR}/include/uppertab.h ${PROJECT_SOURCE_DIR}/include/lowertab.h
  COMMAND $<TARGET_FILE:gen_casetab> ${PROJECT_SOURCE_DIR}/data/UnicodeData.txt ${PROJECT_SOURCE_DIR}/include
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/data/UnicodeData.txt
  DEPENDS gen_casetab
  VERBATIM
)

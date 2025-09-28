target_sources(${PROJECT_NAME} PRIVATE
  casecvt.cpp
  ini.cpp
  utf8.cpp
)

# Windows specific stuff
if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
  target_sources(${PROJECT_NAME} PRIVATE
    buffer.cpp
    win.cpp
  )
endif ()

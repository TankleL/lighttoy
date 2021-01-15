
file(GLOB LIBTOY_INCLUDE_FILES "inc/*.hpp")
set(LIBTOY_SOURCE_FILES
  src/visual-node.cpp
)

add_library(libtoy STATIC 
  ${LIBTOY_INCLUDE_FILES}
  ${LIBTOY_SOURCE_FILES}
)

target_include_directories(libtoy PUBLIC inc)

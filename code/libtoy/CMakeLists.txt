
set(LIBTOY_INCLUDE_FILES
  inc/libtoy.hpp
  inc/prerequisites.hpp
  inc/exceptions.hpp
  inc/imgutils.hpp
  inc/texture2d.hpp
  inc/visual-node.hpp
)

set(LIBTOY_SOURCE_FILES
  src/visual-node.cpp
)

add_library(libtoy STATIC 
  ${LIBTOY_INCLUDE_FILES}
  ${LIBTOY_SOURCE_FILES}
)

target_include_directories(libtoy PUBLIC inc)
target_include_directories(libtoy PUBLIC ${EIGEN_INCLUDE})

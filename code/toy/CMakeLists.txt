
file(GLOB TOY_INCLUDE_FILES "inc/*.hpp")
set(TOY_SOURCE_FILES
  src/main.cpp
)

add_executable(toy
  ${TOY_INCLUDE_FILES}
  ${TOY_SOURCE_FILES}
)

target_include_directories(toy PRIVATE ${LIBTOY_INCLUDE})
target_link_libraries(toy libtoy)

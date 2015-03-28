set(BII_LIB_DEPS "pthread -ldl")

ADD_BIICODE_TARGETS()
#TARGET_INCLUDE_DIRECTORIES(${BII_BLOCK_TARGET} INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/../foonathan_string_id/foonathan/string_id")


IF(APPLE)
  TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11 -stdlib=libc++")
ELSEIF (WIN32 OR UNIX)
  TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11")
ENDIF(APPLE)


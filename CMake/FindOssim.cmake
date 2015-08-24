# - Find Ossim
# Find the native Ossim includes and library
#
#   OSSIM_FOUND        - True if Ossim found.
#   OSSIM_INCLUDE_DIRS - where to find ossim/init/ossimInit.h, etc.
#   OSSIM_LIBRARIES    - List of libraries when using Ossim.
#

if( OSSIM_INCLUDE_DIR )
    # Already in cache, be silent
    set( Ossim_FIND_QUIETLY TRUE )
endif()

find_path( OSSIM_INCLUDE_DIR
           NAMES ossim/init/ossimInit.h )

if(EXISTS "${OSSIM_INCLUDE_DIR}/ossim/ossimVersion.h")
  file(READ "${OSSIM_INCLUDE_DIR}/ossim/ossimVersion.h" _ossim_version_h_CONTENTS)
  string(REGEX REPLACE ".*# *define OSSIM_VERSION *\"([0-9.]+)\".*" "\\1" OSSIM_VERSION "${_ossim_version_h_CONTENTS}")
  string(REGEX REPLACE "([0-9]+)\\.([0-9]+)\\.([0-9]+)" "\\1" OSSIM_MAJOR_VERSION_NUMBER "${OSSIM_VERSION}")
  string(REGEX REPLACE "([0-9]+)\\.([0-9]+)\\.([0-9]+)" "\\2" OSSIM_MINOR_VERSION_NUMBER "${OSSIM_VERSION}")
  string(REGEX REPLACE "([0-9]+)\\.([0-9]+)\\.([0-9]+)" "\\3" OSSIM_PATCH_VERSION_NUMBER "${OSSIM_VERSION}")
  math(EXPR OSSIM_VERSION_NUMBER
    "((${OSSIM_MAJOR_VERSION_NUMBER})*100+${OSSIM_MINOR_VERSION_NUMBER})*100+${OSSIM_PATCH_VERSION_NUMBER}")
else()
  if(NOT Ossim_FIND_QUIETLY)
  message(WARNING "ossimVersion.h not found !")
  endif()
endif()

find_library(OSSIM_LIBRARY
             NAMES ossim)

# handle the QUIETLY and REQUIRED arguments and set OSSIM_FOUND to TRUE if
# all listed variables are TRUE
include( FindPackageHandleStandardArgs )
FIND_PACKAGE_HANDLE_STANDARD_ARGS( Ossim DEFAULT_MSG OSSIM_LIBRARY OSSIM_INCLUDE_DIR )

mark_as_advanced( OSSIM_INCLUDE_DIR OSSIM_LIBRARY )

set(OSSIM_LIBRARIES ${OSSIM_LIBRARY})
set(OSSIM_INCLUDE_DIRS ${OSSIM_INCLUDE_DIR})

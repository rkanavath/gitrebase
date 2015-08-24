set(proj JPEG)

if(NOT __EXTERNAL_${proj}__)
set(__EXTERNAL_${proj}__ 1)

message(STATUS "Setup libjpeg...")

if(USE_SYSTEM_JPEG)
  find_package ( JPEG )
  add_custom_target(${proj})
  message(STATUS "  Using libjpeg system version")
else()
  SETUP_SUPERBUILD(PROJECT ${proj})
  message(STATUS "  Using libjpeg SuperBuild version")
  
  if(WIN32)
    ExternalProject_Add(${proj}
      PREFIX ${proj}
      URL "http://www.ijg.org/files/jpegsrc.v9a.tar.gz"
      URL_MD5 3353992aecaee1805ef4109aadd433e7
      SOURCE_DIR ${JPEG_SB_SRC}
      BINARY_DIR ${JPEG_SB_BUILD_DIR}
      INSTALL_DIR ${SB_INSTALL_PREFIX}
      DOWNLOAD_DIR ${DOWNLOAD_LOCATION}
      PATCH_COMMAND ${CMAKE_COMMAND} -E copy  ${CMAKE_SOURCE_DIR}/patches/${proj}/CMakeLists.txt ${JPEG_SB_SRC}
      CMAKE_CACHE_ARGS
        -DCMAKE_INSTALL_PREFIX:STRING=${SB_INSTALL_PREFIX}
        -DCMAKE_BUILD_TYPE:STRING=Release
        -DCMAKE_VERBOSE_MAKEFILE:BOOL=OFF
    )

    ExternalProject_Add_Step(${proj} copy_jconfig
      COMMAND ${CMAKE_COMMAND} -E copy 
        ${JPEG_SB_SRC}/jconfig.vc ${JPEG_SB_SRC}/jconfig.h
      DEPENDEES patch
      DEPENDERS build
    )

  else()
    
    ExternalProject_Add(${proj}
      PREFIX ${proj}
      URL "http://www.ijg.org/files/jpegsrc.v9a.tar.gz"
      URL_MD5 3353992aecaee1805ef4109aadd433e7
      BINARY_DIR ${JPEG_SB_BUILD_DIR}
      INSTALL_DIR ${SB_INSTALL_PREFIX}
      DOWNLOAD_DIR ${DOWNLOAD_LOCATION}
      CONFIGURE_COMMAND
        ${JPEG_SB_BUILD_DIR}/configure
        --prefix=${SB_INSTALL_PREFIX}
        --enable-shared=yes
      BUILD_COMMAND $(MAKE)
      INSTALL_COMMAND $(MAKE) install
      DEPENDS ${${proj}_DEPENDENCIES}
      )
    
    ExternalProject_Add_Step(${proj} copy_source
      COMMAND ${CMAKE_COMMAND} -E copy_directory 
        ${JPEG_SB_SRC} ${JPEG_SB_BUILD_DIR}
      DEPENDEES patch update
      DEPENDERS configure
      )
    
  endif()
  
  set(_SB_${proj}_INCLUDE_DIR ${SB_INSTALL_PREFIX}/include)
    if(WIN32)
      set(_SB_${proj}_LIBRARY ${SB_INSTALL_PREFIX}/lib/libjpeg.lib)
    elseif(UNIX)
      set(_SB_${proj}_LIBRARY ${SB_INSTALL_PREFIX}/lib/libjpeg${CMAKE_SHARED_LIBRARY_SUFFIX})
    endif()
  
endif()
endif()

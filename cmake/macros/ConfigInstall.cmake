#
# This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#

#
# Use it like:
# CopyApplicationConfig(${APP_PROJECT_NAME} ${APPLICATION_NAME})
#

function(CopyApplicationConfig projectName appName)
  GetPathToApplication(${appName} SOURCE_APP_PATH)

  if(WIN32)
    if("${CMAKE_MAKE_PROGRAM}" MATCHES "MSBuild")
      add_custom_command(TARGET ${projectName}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/configs")
      add_custom_command(TARGET ${projectName}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${SOURCE_APP_PATH}/${appName}.conf.dist" "${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/configs")
    elseif(MINGW)
      add_custom_command(TARGET ${servertype}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/bin/configs")
      add_custom_command(TARGET ${servertype}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${SOURCE_APP_PATH}/${appName}.conf.dist ${CMAKE_BINARY_DIR}/bin/configs")
    endif()
  endif()

  if(UNIX)
    install(FILES "${SOURCE_APP_PATH}/${appName}.conf.dist" DESTINATION "${CONF_DIR}")
  elseif(WIN32)
    install(FILES "${SOURCE_APP_PATH}/${appName}.conf.dist" DESTINATION "${CMAKE_INSTALL_PREFIX}/configs")
  endif()
endfunction()

function(CopyToolConfig projectName appName)
  GetPathToTool(${appName} SOURCE_APP_PATH)

  if(WIN32)
    if("${CMAKE_MAKE_PROGRAM}" MATCHES "MSBuild")
      add_custom_command(TARGET ${projectName}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/configs")
      add_custom_command(TARGET ${projectName}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${SOURCE_APP_PATH}/${appName}.conf.dist" "${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/configs")
    elseif(MINGW)
      add_custom_command(TARGET ${servertype}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/bin/configs")
      add_custom_command(TARGET ${servertype}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${SOURCE_APP_PATH}/${appName}.conf.dist ${CMAKE_BINARY_DIR}/bin/configs")
    endif()
  endif()

  if(UNIX)
    install(FILES "${SOURCE_APP_PATH}/${appName}.conf.dist" DESTINATION "${CONF_DIR}")
  elseif(WIN32)
    install(FILES "${SOURCE_APP_PATH}/${appName}.conf.dist" DESTINATION "${CMAKE_INSTALL_PREFIX}/configs")
  endif()
endfunction()

#
# Use it like:
# CopyModuleConfig("acore.conf.dist")
#

function(CopyModuleConfig configDir)
  set(postPath "configs/modules")

  if(WIN32)
    if("${CMAKE_MAKE_PROGRAM}" MATCHES "MSBuild")
      add_custom_command(TARGET modules
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/${postPath}")
      add_custom_command(TARGET modules
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${configDir}" "${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/${postPath}")
    elseif(MINGW)
      add_custom_command(TARGET modules
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/bin/${postPath}")
      add_custom_command(TARGET modules
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${configDir} ${CMAKE_BINARY_DIR}/bin/${postPath}")
    endif()
  endif()

  if(UNIX)
    install(FILES "${configDir}" DESTINATION "${CONF_DIR}/modules")
  elseif(WIN32)
    install(FILES "${configDir}" DESTINATION "${CMAKE_INSTALL_PREFIX}/${postPath}")
  endif()
  unset(postPath)
endfunction()

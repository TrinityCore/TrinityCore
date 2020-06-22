# Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

macro(GroupSources dir)
  # Skip this if WITH_SOURCE_TREE is not set (empty string).
  if(NOT ${WITH_SOURCE_TREE} STREQUAL "")
    # Include all header and c files
    file(GLOB_RECURSE elements RELATIVE ${dir} *.h *.hpp *.c *.cpp *.cc)

    foreach(element ${elements})
      # Extract filename and directory
      get_filename_component(element_name ${element} NAME)
      get_filename_component(element_dir ${element} DIRECTORY)

      if(NOT ${element_dir} STREQUAL "")
        # If the file is in a subdirectory use it as source group.
        if(${WITH_SOURCE_TREE} STREQUAL "flat")
          # Build flat structure by using only the first subdirectory.
          string(FIND ${element_dir} "/" delemiter_pos)
          if(NOT ${delemiter_pos} EQUAL -1)
            string(SUBSTRING ${element_dir} 0 ${delemiter_pos} group_name)
            source_group("${group_name}" FILES ${dir}/${element})
          else()
            # Build hierarchical structure.
            # File is in root directory.
            source_group("${element_dir}" FILES ${dir}/${element})
          endif()
        else()
          # Use the full hierarchical structure to build source_groups.
          string(REPLACE "/" "\\" group_name ${element_dir})
          source_group("${group_name}" FILES ${dir}/${element})
        endif()
      else()
        # If the file is in the root directory, place it in the root source_group.
        source_group("\\" FILES ${dir}/${element})
      endif()
    endforeach()
  endif()
endmacro()

if(WITH_SOURCE_TREE STREQUAL "hierarchical-folders")
  # Use folders
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

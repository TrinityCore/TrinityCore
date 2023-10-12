#!/usr/bin/env python3

import re, os, shutil, stat, subprocess

TACTLIB_GITHUB_REPOSITORY = "https://github.com/overtools/TACTLib"
TACTLIB_ROOT_SUBDIRECTORY = "./TACTLib"
TACTLIB_CMF_SUBDIRECTORY = os.path.join(TACTLIB_ROOT_SUBDIRECTORY, "TACTLib/Core/Product/Tank/CMF")
CPP_BLOCK_INDENT = "    "


def create_file_backup(file_name):
    try:
        file_name_backup = file_name + ".bak"
        backup_index = 1
        while os.path.isfile(file_name_backup):
            file_name_backup = file_name + ".b%02u" % backup_index
            backup_index += 1
        shutil.copyfile(file_name, file_name_backup)
    except Exception as e:
        return False
    return True


def delete_directory(folder_name):
    try:
        for fs_item in os.listdir(folder_name):
            full_path = os.path.join(folder_name, fs_item)
            if os.path.isdir(full_path):
                delete_directory(full_path)
            else:
                os.chmod(full_path, stat.S_IWRITE)
                os.remove(full_path)
        os.rmdir(folder_name)
    except Exception as e:
        pass


def get_file_build_number(plain_name):
    try:
        string_index1 = plain_name.find("_")
        if string_index1 == -1:
            return 0
        string_index1 += 1

        string_index2 = plain_name.find(".")
        if string_index2 < string_index1:
            return 0

        return int(plain_name[string_index1:string_index2])
    except:
        pass
    return 0


def load_build_number_list(folder_name):

    # Create the list of available build numbers
    build_number_list = []

    # Enumerate files in that folder and scan all files with names like "ProCMF_######.cs"
    for plain_name in os.listdir(folder_name):

        # Retrieve the build number from that file name
        build_number = get_file_build_number(plain_name)
        if not build_number:
            continue

        # Append the build number to the list
        build_number_list.append(build_number)

    # Make it sorted
    build_number_list.sort()
    return build_number_list


def append_token(line_buffer, token):
    if len(line_buffer):
        line_buffer = line_buffer + " "
    return line_buffer + token


def flush_line(cmf_cpp, line_buffer, closing_token, nest_level, nest_increment):

    # Setup the indent line
    indent_line = CPP_BLOCK_INDENT * nest_level

    # If there is some remaining items in the single line, flush it to the stream
    if len(line_buffer) != 0:
        cmf_cpp.append(indent_line + line_buffer)
    line_buffer = ""

    # Opening a new block?
    if nest_increment == +1:
        cmf_cpp.append(indent_line + closing_token)
        return "", nest_level + 1

    # Closing a block?
    if nest_increment == -1:
        indent_line = CPP_BLOCK_INDENT * (nest_level - 1)
        cmf_cpp.append(indent_line + closing_token)
        return "", nest_level - 1

    # Move the nest level
    return "", nest_level


def append_hex_array(cmf_cpp, header_line, key_table_tokens, nest_level):

    # Initialization
    inside_block = False
    indent_line = CPP_BLOCK_INDENT * nest_level
    line_buffer = ""
    hexa_values = 0

    # Append the heading line
    cmf_cpp.append(indent_line + header_line)

    # Parse the tokens
    for token in key_table_tokens:

        # Skip spaces
        if token == "":
            continue

        # Block opening
        if token == "{" and inside_block == False:
            line_buffer, nest_level = flush_line(cmf_cpp, line_buffer, "{", nest_level, +1)
            inside_block = True
            hexa_values = 0
            continue

        # Block closing
        if token == "};" and inside_block == True:
            line_buffer, nest_level = flush_line(cmf_cpp, line_buffer, "};", nest_level, -1)
            inside_block = False
            break

        # A hexa value
        if token.startswith("0x") or token.startswith("0X"):
            if hexa_values >= 16:
                line_buffer, nest_level = flush_line(cmf_cpp, line_buffer, None, nest_level, 0)
                hexa_values = 0

            line_buffer = append_token(line_buffer, token)
            hexa_values += 1
            continue

        # An unexpected token
        print("[x] Unexpected token: " + token)

    # The line should be empty here
    assert len(line_buffer) == 0, f"Unexpected remained in the single line: {line_buffer}"
    assert nest_level == 1, f"Unexpected nest level: {nest_level}"
    return


def append_cpp_function(cmf_cpp, header_line, key_table_tokens, nest_level):

    # Initialization
    indent_line = CPP_BLOCK_INDENT * nest_level
    skipping_buffer_allocation = True
    save_nest_level = nest_level
    skipping_definition = True
    inside_for_header = False
    inside_case_label = False
    line_buffer = ""

    # Append the heading line
    cmf_cpp.append(indent_line + header_line)

    # Parse the tokens
    for token in key_table_tokens:

        # Skip spaces
        if token == "":
            continue

        # Skip the function definition
        if skipping_definition:
            if token.endswith(")"):
                skipping_definition = False
            continue

        # Opening brace
        if token == "{":
            line_buffer, nest_level = flush_line(cmf_cpp, line_buffer, "{", nest_level, +1)
            continue

        # Closing brace
        if token == "}":
            line_buffer, nest_level = flush_line(cmf_cpp, line_buffer, "}", nest_level, -1)
            if nest_level == save_nest_level:
                break
            continue

        # Skipping the buffer declaration
        if skipping_buffer_allocation:

            # Append the token to the line
            if len(line_buffer) == 0:
                line_buffer = append_token(line_buffer, "//")
            line_buffer = append_token(line_buffer, token)

            if token.endswith(";"):
                line_buffer, nest_level = flush_line(cmf_cpp, line_buffer, None, nest_level, 0)
                skipping_buffer_allocation = False
            continue

        # Anything else - append to the line buffer
        line_buffer = append_token(line_buffer, token)

        # Handle the begin and end of the "case" label
        if token == "case":
            inside_case_label = True
        if inside_case_label and token.endswith(":"):
            line_buffer, nest_level = flush_line(cmf_cpp, line_buffer, "", nest_level, +1)
            continue
        if inside_case_label and token == "break;":
            line_buffer, nest_level = flush_line(cmf_cpp, line_buffer, "", nest_level, -1)
            continue

        # Handle the begin and end of the "for" header
        if token == "for" or token.startswith("for("):
            inside_for_header = True
            cmf_cpp.append("")
        if inside_for_header and token.endswith(")"):
            line_buffer, nest_level = flush_line(cmf_cpp, line_buffer, None, nest_level, 0)
            inside_for_header = False
            continue

        # End of line
        if token.endswith(";"):
            if inside_for_header == False:
                line_buffer, nest_level = flush_line(cmf_cpp, line_buffer, None, nest_level, 0)
            continue

    return


def build_cmf_cpp(file_content_cs, key_table, key_function, iv_function, build_number):
    cmf_cpp = []

    # Build the header
    cmf_cpp.append("//")
    cmf_cpp.append("// Key+IV provider for build %u. Created automatically, DO NOT EDIT." % build_number)
    cmf_cpp.append("// Source: .\TACTLib\TACTLib\Core\Product\Tank\CMF\ProCMF_%s.cs" % build_number)
    cmf_cpp.append("//\n")

    # Append the begin of the namespace
    cmf_cpp.append("namespace KeyCMF_%06u" % build_number)
    cmf_cpp.append("{")

    # Append the key table
    key_table_tokens = re.split(r"\s+", file_content_cs[key_table.end():])
    append_hex_array(cmf_cpp, "static const BYTE Keytable[] =", key_table_tokens, 1)
    cmf_cpp.append("")

    # Append the key generation function
    key_table_tokens = re.split(r"\s+", file_content_cs[key_function.end():])
    append_cpp_function(cmf_cpp, "LPBYTE Key(const CASC_CMF_HEADER & header, LPBYTE buffer, int length)", key_table_tokens, 1)
    cmf_cpp.append("")

    # Append the IV generation function
    iv_table_tokens = re.split(r"\s+", file_content_cs[iv_function.end():])
    append_cpp_function(cmf_cpp, "LPBYTE IV(const CASC_CMF_HEADER & header, LPBYTE digest, LPBYTE buffer, int length)", iv_table_tokens, 1)
    cmf_cpp.append("}")
    return cmf_cpp


def convert_cs_to_cpp_cmf(source_file, target_file, build_number):

    # Load the content of the file to memory
    try:
        file_content = None
        with open(source_file, "rt") as f:
            file_content_cs = f.read()
    except Exception as e:
        return False

    # Locate the KeyTable, Key() and IV() procedures
    try:
        search_regexp = r"private\s+static\s+readonly\s+byte\s*\[\] +Keytable +="
        key_table = re.search(search_regexp, file_content_cs, re.I)
        if key_table is None:
            print("\n[x] Failed to find the key table")
            return 0
    except Exception as e:
        return False

    # Locate the function for the key generation
    try:
        search_regexp = r"public\s+byte\s*\[\]\s*Key\s*"
        key_function = re.search(search_regexp, file_content_cs, re.I)
        if key_function is None:
            print("\n[x] Failed to find the Key() function")
            return 0
    except Exception as e:
        return False

    # Locate the function for the IV generation
    try:
        search_regexp = r"public\s+byte\s*\[\]\s*IV\s*"
        iv_function = re.search(search_regexp, file_content_cs, re.I)
        if iv_function is None:
            print("\n[x] Failed to find the IV() function")
            return 0
    except Exception as e:
        return False

    # Generate the content of the C++ file
    try:
        file_content_cpp = build_cmf_cpp(file_content_cs, key_table, key_function, iv_function, build_number)
        if file_content_cpp is None:
            print("\n[x] Failed to build the CPP file")
            return 0
    except Exception as e:
        return False

    # Write the content of the file
    try:
        target_file.writelines(single_line + "\n" for single_line in file_content_cpp)
        target_file.write("\n")
    except Exception as e:
        return 0
    return 1


def create_cmf_key_cpp(file_name):

    # Create backup of the file
    if not create_file_backup(file_name):
        return False

    # Create the file
    try:
        file = open(file_name, "wt")
    except Exception as e:
        return False

    # Write the initial comment
    file.write("//\n")
    file.write("// This file was converted from the sources of TACTLib. DO NOT EDIT.\n")
    file.write("// Source: https://github.com/overtools/TACTLib\n")
    file.write("//\n\n")
    return file


def download_TACTLib_repository():
    try:
        # Show what we're doing
        print("[*] Downloading TACTLib ...")

        # Run git clone
        process = subprocess.Popen(["git", "clone", TACTLIB_GITHUB_REPOSITORY + ".git"], stderr=subprocess.PIPE, stdout=None)
        process_output = process.communicate()[1].decode("ascii")

        # Check for success
        if process_output.startswith("Cloning into "):
            return True

        # Check for existing directory
        if process_output.endswith("already exists and is not an empty directory.\n"):
            return True
    except subprocess.CalledProcessError as e:
        pass
    return False


def update_CascLib_repository():
    try:
        # Show what we're doing
        print("[*] Updating git repository ...")

        # Run git clone
        process = subprocess.Popen(["git", "add", ".\cmf"], stderr=subprocess.PIPE, stdout=None)
        process_output = process.communicate()[1].decode("ascii")
        return True
    except subprocess.CalledProcessError as e:
        pass
    return False


def check_TACTLib_repository(folder_name):
    try:
        print("[*] Checking the downloaded folder ...")
        source_file_list = os.listdir(folder_name)
        if len(source_file_list) != 0:
            return True
    except Exception as e:
        pass
    return False


def process_TACTLib_repository():

    # Initialization
    print("[*] Gathering build numbers ...")
    folder_name = os.path.abspath(TACTLIB_CMF_SUBDIRECTORY)
    build_number_list = load_build_number_list(folder_name)

    # Create the new cmf-key.cpp
    print("[*] Writing the source of providers ...")
    target_file = create_cmf_key_cpp("cmf-key.cpp")
    if target_file is None:
        return False

    # Write warning supression
    target_file.write("// Supress warnings that may be raised by the converted C# code\n")
    target_file.write("#ifdef _MSC_VER\n")
    target_file.write("#pragma warning(push)\n")
    target_file.write("#pragma warning(disable: 4100)  // warning C4100: 'header': unreferenced formal parameter\n")
    target_file.write("#pragma warning(disable: 4389)  // warning C4389: '!=': signed/unsigned mismatch\n")
    target_file.write("#endif  // _MSC_VER\n\n")

    # Convert every file in the directory
    for build_number in build_number_list:

        # Show the processed file name
        plain_name = "ProCMF_%u.cs" % build_number
        source_file = os.path.join(folder_name, plain_name)
        print("[*] %s ... " % source_file, end="")

        # Convert the content of the file into the cmf-key.cpp
        if convert_cs_to_cpp_cmf(source_file, target_file, build_number) == 0:
            break
        print("(OK)")

    # Write the table that contains the list of providers
    print("[*] Writing the table of providers ...")
    build_number_list.sort()
    target_file.write("// Sorted list of Key+IV providers. DO NOT EDIT.\n")
    target_file.write("static const CASC_CMF_KEY_PROVIDER CmfKeyProviders[] =\n")
    target_file.write("{\n")

    # Write the entries
    for build_number in build_number_list:
        target_file.write("    {%6u, KeyCMF_%06u::Key, KeyCMF_%06u::IV},\n" % (build_number, build_number, build_number))
    target_file.write("};\n\n")

    # Write the end of warnings
    target_file.write("#ifdef _MSC_VER\n")
    target_file.write("#pragma warning(pop)\n")
    target_file.write("#endif  // _MSC_VER\n")

    # Write the tail
    target_file.close()
    return True


def perform_TACTLib_update():

    # Download the content of the "TACTLib package"
    if not download_TACTLib_repository():
        print("[x] Failed to download the TACTLib library")
        return

    # Did we download something?
    if not check_TACTLib_repository(TACTLIB_CMF_SUBDIRECTORY):
        print("[x] It seems that the download failed")
        return

    # Create list of the supported game builds
    if not process_TACTLib_repository():
        print("[x] Failed to update the key providers")
        return

    if not update_CascLib_repository():
        print("[x] Failed to update the git repository")
        return


def perform_TACTLib_cleanup():
    print("[*] Cleaning up")
    folder_name = os.path.abspath(TACTLIB_ROOT_SUBDIRECTORY)
    delete_directory(folder_name)


if __name__ == '__main__':
    perform_TACTLib_update()
    perform_TACTLib_cleanup()
    print("[*] Complete")


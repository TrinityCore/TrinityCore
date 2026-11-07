<!--- (**********************************)
      (** Fill in the following fields **)
      (**********************************)
      (you can delete all rows before description and after operating system when creating issue)
      For SQL fixes:
      search for existing issues, if a bug report exist for the issue you are trying to fix and it's opened post there.
      don't modify WDB fields without supply one sniff of those fields (censure guids, character names, anything blizzard can use to identify source)
      don't use pull requests for sql only fixes, unless it's to fix one existing unable to apply file.
      don't hardcode guids.
      don't DELETE + INSERT to update only few fields of one row.
      don't use database names.
      don't put ' around numbers.
      don't put ( ) if they aren't needed.
      use only 1 DELETE + INSERT when we add multiple items to one table, unless you are scripting multiple creatures.
      start fix by -- in case some previous sql misses proper ending.
      DELETE by guid AND entry to be sure we don't delete existing spawns.
      start sql code with 3 ` sql         --->

**Description:**

CHANGEME Description of the problem or issue here.
If this is a crash, post the crashlog (upload to https://gist.github.com/).

**Expected behaviour:**

CHANGEME Tell us what should happen instead.

**Steps to reproduce the problem:**

1. CHANGEME Step 1 include entries of affected creatures / items / quests with a link to the relevant wowhead page.  
2. Step 2
3. Step 3

**Branch(es):**

CHANGEME 3.3.5, master, cata_classic or all

**TC rev. hash/commit:** 

CHANGEME Copy the result of server debug command (if you need to run it from client get prat addon)

**Operating system:** 

CHANGEME OS


<!--- Notes
- This template is for problem reports. For other types of report, edit it accordingly.
- For fixes containing C++ changes, create a Pull Request.
--->

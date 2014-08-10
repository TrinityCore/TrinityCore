####About
Allows you to show gossip options that show different vendors from npc_vendor.<br />
Source: http://rochet2.github.io/?page=Multivendor

####Installation
Download gist<br />
Apply the the diff with git bash using command `git apply MultiVendor.diff`<br />
Supported TC version: https://github.com/TrinityCore/TrinityCore/commit/2042b095266cabd79b26d8325d4dee600260d4c9

####Usage
Set your NPC to have gossip and vendor NPCflags (129)<br />
Add a gossip menu for him and add a new option to it.<br />
The option needs to have option_id set to 3 so it acts as a vendor button,<br />
npc_option_npcflag can be 1 or 128 (shows only if the NPC has vendor flag then)<br />
and the action_menu_id is the vendor entry from npc_vendor that you want to show to the player.<br />

YOU CAN also send menus from C++. All you need to do is to provide the vendor entry to the<br />
`void WorldSession::SendListInventory(uint64 vendorGuid, uint32 vendorEntry)` function.

The npc add item command was modified so you can add items to multivendors as well.<br />
The last vendor window must have been the multivendor you want to add your item to.<br />
After opening the window you need to type `.npc add item #itemId <#maxcount><#incrtime><#extendedcost> 1`<br />
The 1 in the end specifies that you are adding the item to the multivendor currently open.<br />
Same thing works with `.npc delete item #itemId 1`

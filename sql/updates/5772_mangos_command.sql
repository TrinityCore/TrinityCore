DELETE FROM `command` WHERE `name` = 'addgo';
DELETE FROM `command` WHERE `name` = 'addquest';
DELETE FROM `command` WHERE `name` = 'addspw';
DELETE FROM `command` WHERE `name` = 'addtele';
DELETE FROM `command` WHERE `name` = 'addvendoritem';
DELETE FROM `command` WHERE `name` = 'addweapon';
DELETE FROM `command` WHERE `name` = 'allowmove';
DELETE FROM `command` WHERE `name` = 'anim';
DELETE FROM `command` WHERE `name` = 'money';
DELETE FROM `command` WHERE `name` = 'morph';
DELETE FROM `command` WHERE `name` = 'movecreature';
DELETE FROM `command` WHERE `name` = 'moveobject';
DELETE FROM `command` WHERE `name` = 'name';
DELETE FROM `command` WHERE `name` = 'nametele';
DELETE FROM `command` WHERE `name` = 'nearobjects';
DELETE FROM `command` WHERE `name` = 'npcflag';
DELETE FROM `command` WHERE `name` = 'npcinfo';
DELETE FROM `command` WHERE `name` = 'npcinfoset';
DELETE FROM `command` WHERE `name` = 'npcwhisper';
DELETE FROM `command` WHERE `name` = 'castback';
DELETE FROM `command` WHERE `name` = 'casttarget';
DELETE FROM `command` WHERE `name` = 'changelevel';
DELETE FROM `command` WHERE `name` = 'delete';
DELETE FROM `command` WHERE `name` = 'delobject';
DELETE FROM `command` WHERE `name` = 'deltele';
DELETE FROM `command` WHERE `name` = 'delvendoritem';
DELETE FROM `command` WHERE `name` = 'drunk';
DELETE FROM `command` WHERE `name` = 'factionid';
DELETE FROM `command` WHERE `name` = 'getvalue';
DELETE FROM `command` WHERE `name` = 'gocreature';
DELETE FROM `command` WHERE `name` = 'gograveyard';
DELETE FROM `command` WHERE `name` = 'gogrid';
DELETE FROM `command` WHERE `name` = 'goobject';
DELETE FROM `command` WHERE `name` = 'gotrigger';
DELETE FROM `command` WHERE `name` = 'goxy';
DELETE FROM `command` WHERE `name` = 'goxyz';
DELETE FROM `command` WHERE `name` = 'gozonexy';
DELETE FROM `command` WHERE `name` = 'grouptele';
DELETE FROM `command` WHERE `name` = 'listcreature';
DELETE FROM `command` WHERE `name` = 'listgm';
DELETE FROM `command` WHERE `name` = 'listitem';
DELETE FROM `command` WHERE `name` = 'listobject';
DELETE FROM `command` WHERE `name` = 'playemote';
DELETE FROM `command` WHERE `name` = 'playsound';
DELETE FROM `command` WHERE `name` = 'removequest';
DELETE FROM `command` WHERE `name` = 'resetall';
DELETE FROM `command` WHERE `name` = 'setmodel';
DELETE FROM `command` WHERE `name` = 'setmovetype';
DELETE FROM `command` WHERE `name` = 'setvalue';
DELETE FROM `command` WHERE `name` = 'spawndist';
DELETE FROM `command` WHERE `name` = 'spawntime';
DELETE FROM `command` WHERE `name` = 'speed';
DELETE FROM `command` WHERE `name` = 'standstate';
DELETE FROM `command` WHERE `name` = 'subname';
DELETE FROM `command` WHERE `name` = 'targetobject';
DELETE FROM `command` WHERE `name` = 'textemote';
DELETE FROM `command` WHERE `name` = 'titles';
DELETE FROM `command` WHERE `name` = 'turnobject';
DELETE FROM `command` WHERE `name` = 'update';
DELETE FROM `command` WHERE `name` = 'visible';

INSERT INTO `command` (`name`,`security`,`help`) VALUES
('cast back',3,'Syntax: .cast back #spellid\r\n  Selected target will cast #spellid to your character.'),
('cast target',3,'Syntax: .cast target #spellid\r\n  Selected target will cast #spellid to his victim.'),
('debug anim',2,'Syntax: .debug anim #emoteid\r\n\r\nPlay emote #emoteid for your character.'),
('debug getvalue',3,'Syntax: .debug getvalue #field #isInt\r\n\r\nGet the field #field of the selected creature. If no creature is selected, get the content of your field.\r\n\r\nUse a #isInt of value 1 if the expected field content is an integer.'),
('debug playsound',1,'Syntax: .debug playsound #soundid\r\n\r\nPlay sound with #soundid.\r\nSound will be play only for you. Other players do not hear this.\r\nWarning: client may have more 5000 sounds...'),
('debug setvalue',3,'Syntax: .debug setvalue #field #value #isInt\r\n\r\nSet the field #field of the selected creature with value #value. If no creature is selected, set the content of your field.\r\n\r\nUse a #isInt of value 1 if #value is an integer.'),
('debug standstate',2,'Syntax: .debug standstate #emoteid\r\n\r\nChange the emote of your character while standing to #emoteid.'),
('debug update',3,'Syntax: .debug update #field #value\r\n\r\nUpdate the field #field of the selected character or creature with value #value.\r\n\r\nIf no #value is provided, display the content of field #field.'),
('gm list',0,'Syntax: .gm list\r\n\r\nDisplay a list of available Game Masters.'),
('gm visible',1,'Syntax: .gm visible on/off\r\n\r\nOutput current visibility state or make GM visible(on) and invisible(off) for other players.'),
('go creature',2,'Syntax: .go creature #creature_guid\r\nTeleport your character to creature with guid #creature_guid.\r\n.gocreature #creature_name\r\nTeleport your character to creature with this name.\r\n.gocreature id #creature_id\r\nTeleport your character to a creature that was spawned from the template with this entry.\r\n*If* more than one creature is found, then you are teleported to the first that is found inside the database.'),
('go graveyard',2,'Syntax: .go graveyard #graveyardId\r\n Teleport to graveyard with the graveyardId specified.'),
('go grid',1,'Syntax: .go grid #gridX #gridY [#mapId]\r\n\r\nTeleport the gm to center of grid with provided indexes at map #mapId (or current map if it not provided).'),
('go object',1,'Syntax: .go object #object_guid\r\nTeleport your character to gameobject with guid #object_guid'),
('go trigger',2,'Syntax: .go trigger #trigger_id\r\n\r\nTeleport your character to areatrigger with id #trigger_id. Character will be teleported to trigger target if selected areatrigger is telporting trigger.'),
('go xy',1,'Syntax: .go xy #x #y [#mapid]\r\n\r\nTeleport player to point with (#x,#y) coordinates at ground(water) level at map #mapid or same map if #mapid not provided.'),
('go xyz',1,'Syntax: .go xyz #x #y #z [#mapid]\r\n\r\nTeleport player to point with (#x,#y,#z) coordinates at ground(water) level at map #mapid or same map if #mapid not provided.'),
('go zonexy',1,'Syntax: .go zonexy #x #y [#zone]\r\n\r\nTeleport player to point with (#x,#y) client coordinates at ground(water) level in zone #zoneid or current zone if #zoneid not provided. You can look up zone using .lookup area $namepart'),
('gobject add',2,'Syntax: .gobject add #id <spawntimeSecs>\r\n\r\nAdd a game object from game object templates to the world at your current location using the #id.\r\nspawntimesecs sets the spawntime, it is optional.\r\n\r\nNote: this is a copy of .gameobject.'),
('gobject delete',2,'Syntax: .gobject delete #go_guid\r\nDelete gameobject with guid #go_guid.'),
('gobject move',2,'Syntax: .gobject move #goguid [#x #y #z]\r\n\r\nMove gameobject #goguid to character coordinates (or to (#x,#y,#z) coordinates if its provide).'),
('gobject near ',3,'Syntax: .gobject near  [#distance]\r\n\r\nOutput gameobjects at distance #distance from player. Output gameobject guids and coordinates sorted by distance from character. If #distance not provided use 10 as default value.'),
('gobject turn',2,'Syntax: .gobject turn #goguid \r\n\r\nSet for gameobject #goguid orientation same as current character orientation.'),
('list creature',3,'Syntax: .list creature #creature_id [#max_count]\r\n\r\nOutput creatures with creature id #creature_id found in world. Output creature guids and coordinates sorted by distance from character. Will be output maximum #max_count creatures. If #max_count not provided use 10 as default value.'),
('list item',3,'Syntax: .list item #item_id [#max_count]\r\n\r\nOutput items with item id #item_id found in all character inventories, mails and auctions. Output item guids, item owner guid, owner account and owner name. Will be output maximum #max_count items. If #max_count not provided use 10 as default value.'),
('list object',3,'Syntax: .list object #gameobject_id [#max_count]\r\n\r\nOutput gameobjects with gameobject id #gameobject_id found in world. Output gameobject guids and coordinates sorted by distance from character. Will be output maximum #max_count gameobject. If #max_count not provided use 10 as default value.'),
('modify drunk',1,'Syntax: .modify drunk #value\r\n Set drunk level to #value (0..100). Value 0 remove drunk state, 100 is max drunked state.'),
('modify morph',2,'Syntax: .modify morph #displayid\r\n\r\nChange your current model id to #displayid.'),
('npc add',2,'Syntax: .npc add #creatureid\r\n\r\nSpawn a creature by the given template id of #creatureid.'),
('npc additem',2,'Syntax: .npc additem #itemId <#maxcount><#incrtime><#extendedcost>r\r\n\r\nAdd item #itemid to item list of selected vendor. Also optionally set max count item in vendor item list and time to item count restoring and items ExtendedCost.'),
('npc addweapon',3,'Not yet implemented.'),
('npc allowmove',3,'Syntax: .npc allowmove\r\n\r\nEnable or disable movement for the selected creature.'),
('npc changelevel',2,'Syntax: .npc changelevel #level\r\n\r\nChange the level of the selected creature to #level.\r\n\r\n#level may range from 1 to 63.'),
('npc delete',2,'Syntax: .npc delete\r\n\r\nDelete the selected creature from the world.'),
('npc delitem',2,'Syntax: .npc delitem #itemId\r\n\r\nRemove item #itemid from item list of selected vendor.'),
('npc factionid',2,'Syntax: .npc factionid #factionid\r\n\r\nSet the faction of the selected creature to #factionid.'),
('npc flag',2,'Syntax: .npc flag #npcflag\r\n\r\nSet the NPC flags of creature template of the selected creature and selected creature to #npcflag. NPC flags will applied to all creatures of selected creature template after server restart or grid unload/load.'),
('npc info',3,'Syntax: .npc info\r\n\r\nDisplay a list of details for the selected creature.\r\n\r\nThe list includes:\r\n- GUID, Faction, NPC flags, Entry ID, Model ID,\r\n- Level,\r\n- Health (current/maximum),\r\n\r\n- Field flags, dynamic flags, faction template, \r\n- Position information,\r\n- and the creature type, e.g. if the creature is a vendor.'),
('npc move',2,'Syntax: .npc move [#creature_guid]\r\n\r\nMove the targeted creature spawn point to your coordinates.'),
('npc name',2,'Syntax: .npc name $name\r\n\r\nChange the name of the selected creature or character to $name.\r\n\r\nCommand disabled.'),
('npc playemote',3,'Syntax: .npc playemote #emoteid\r\n\r\nMake the selected creature emote with an emote of id #emoteid.'),
('npc setmodel',2,'Syntax: .npc setmodel #displayid\r\n\r\nChange the model id of the selected creature to #displayid.'),
('npc setmovetype',2,'Syntax: .npc setmovetype [#creature_guid] stay/random/way [NODEL]\r\n\r\nSet for creature pointed by #creature_guid (or selected if #creature_guid not provided) movement type and move it to respawn position (if creature alive). Any existing waypoints for creature will be removed from the database if you do not use NODEL. If the creature is dead then movement type will applied at creature respawn.\r\nMake sure you use NODEL, if you want to keep the waypoints.'),
('npc spawndist',2,'Syntax: .npc spawndist #dist\r\n\r\nAdjust spawndistance of selected creature to dist.'),
('npc spawntime',2,'Syntax: .npc spawntime #time \r\n\r\nAdjust spawntime of selected creature to time.'),
('npc subname',2,'Syntax: .npc subname $Name\r\n\r\nChange the subname of the selected creature or player to $Name.\r\n\r\nCommand disabled.'),
('npc textemote',3,'Syntax: .npc textemote #emoteid\r\n\r\nMake the selected creature to do textemote with an emote of id #emoteid.'),
('npc whisper',1,'Syntax: .npc whisper #playerguid #text\r\nMake the selected npc whisper #text to  #playerguid.'),
('quest add',3,'Syntax: .quest add #quest_id\r\n\r\nAdd to character quest log quest #quest_id. Quest started from item can\'t be added by this command but correct .additem call provided in command output.'),
('quest remove',3,'Syntax: .quest remove #quest_id\r\n\r\nSet quest #quest_id state to not completed and not active (and remove from active quest list) for selected player.'),
('reset all',3,'Syntax: .reset all spells\r\n\r\nSyntax: .reset all talents\r\n\r\nRequest reset spells or talents at next login each existed character.'),
('targetobject',2,'Syntax: .gobject target[#go_id|#go_name_part]\r\n\r\nLocate and show position nearest gameobject. If #go_id or #go_name_part provide then locate and show position of nearest gameobject with gameobject template id #go_id or name included #go_name_part as part.'),
('tele add',3,'Syntax: .tele add $name\r\n\r\nAdd current your position to .tele command target locations list with name $name.'),
('tele del',3,'Syntax: .tele del $name\r\n\r\nRemove location with name $name for .tele command locations list.'),
('tele group',1,'Syntax: .tele group#location\r\n\r\nTeleport a selected player and his group members to a given location.'),
('tele name',1,'Syntax: .tele name #playername #location\r\n\r\nTeleport a player to a given location.');
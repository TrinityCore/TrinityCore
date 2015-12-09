#
# CHANGE ORIGINAL PERMISSIONS
#
# Current original Roles are:
# 198 Moderator Commands
# 197 GameMaster Commands
# 196 Administrator Commands
#
# 195: Player 0
# 194: Moderator 1
# 193: GameMaster 2
# 192: Administrator 3
#
DELETE FROM `rbac_linked_permissions` WHERE `id` = 194 AND `linkedId` IN  (25,26,27,28,29);
DELETE FROM `rbac_linked_permissions` WHERE `id` = 198 AND `linkedId` IN  (532,515,597,598,599,600);

# QUERY TO CHECK IF THEY DIDN'T CHANGE PERMISSIONS:
# SELECT * FROM rbac_linked_permissions WHERE id IN ( 25,26,27,28,29,51 );

REPLACE INTO `rbac_linked_permissions` VALUES
#Allow say chat between factions
(195,25),
#Allow channel chat between factions
(195,26),
#Two side mail interaction
(195,27),
#See two side who list
(195,28),
#Add friends of other faction
(195,29),
#Allow trading between factions
(195,51),
#Adding mute and unmute commands to "GameMaster commands"(197)
(197, 532), # Command: unmute
(197, 515), # Command: mute
# Adding some .npc * commands to "GameMaster commands"(197)
(197, 597), # Command: npc say
(197, 598), # Command: npc texemote
(197, 599), # Command: npc whisper
(197, 600); # Command: npc yell

#
# ADD CUSTOM PERMISSIONS
#

# move to GM level 3 some dangerous commands
UPDATE `rbac_linked_permissions` SET `id` = 192 WHERE `id` < 200 AND `linkedId` IN (
  772, # Command: wp unload
  771, # Command: wp modify
  770, # Command: wp load
  769, # Command: wp event
  768, # Command: wp add
  595, # Command: npc move
  591, # Command: npc set spawntime
  590, # Command: npc set spawndist
  589, # Command: npc set phase
  588, # Command: npc set movetype
  587, # Command: npc set model
  586, # Command: npc set link
  585, # Command: npc set level
  584, # Command: npc set flag
  583, # Command: npc set factionid
  580, # Command: npc set
  579, # Command: npc add follow stop
  578, # Command: npc add follow
  577, # Command: npc add delete item
  576, # Command: npc add delete
  575, # Command: npc add temp
  574, # Command: npc add move
  573, # Command: npc add item
  572, # Command: npc add formation
  399, # Command: gobject turn
  397, # Command: gobject set state
  396, # Command: gobject set phase
  395, # Command: gobject set
  393, # Command: gobject move
  391, # Command: gobject delete
  390, # Command: gobject add temp
  389, # Command: gobject add
  370, # Command: event stop
  369  # Command: event start
);

# delete custom commands
DELETE FROM `rbac_linked_permissions` WHERE `linkedId` > 1000 AND `linkedId` < 3000;

# delete custom roles
DELETE FROM `rbac_linked_permissions` WHERE `id` >= 100000;
DELETE FROM `rbac_linked_permissions` WHERE `linkedId` >= 100000;

SET FOREIGN_KEY_CHECKS=0; -- disable temporary FKEY check

DELETE FROM `rbac_permissions` WHERE id >= 100000;

INSERT INTO `rbac_permissions` (`id`, `name`) VALUES('100000','Role: Azeroth [Reserved]');
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES('100001','Role: Azeroth GM Tier 1 ( Supporter )');
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES('100002','Role: Azeroth GM Tier 2 ( Protector )');
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES('100003','Role: Azeroth GM Tier 3 ( da definire )');
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES('100010','Role: Story Teller');
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES('100011','Role: Test Player');
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES('100012','Role: Azeroth Player');
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES('100013','Role: Test GM');

SET FOREIGN_KEY_CHECKS=1; -- re-enable foreign key check

#add default permissions 
DELETE FROM `rbac_default_permissions` WHERE permissionId >= 100000;

INSERT INTO `rbac_default_permissions` (`secId`, `permissionId`, `realmId`) VALUES ('0', '100011', 2); 
INSERT INTO `rbac_default_permissions` (`secId`, `permissionId`, `realmId`) VALUES ('2', '100013', 2); 
INSERT INTO `rbac_default_permissions` (`secId`, `permissionId`) VALUES ('0', '100012'); 

# Query to check current used permissions
# SELECT * FROM rbac_permissions WHERE id IN (SELECT linkedId FROM rbac_linked_permissions WHERE id >= 100000);


# TIER 1: Supporter - Player
INSERT INTO `rbac_linked_permissions` VALUES
(100001,194),    # inheriting from GM 1 ( it shouldn't be necessary but needed for research )
(100001,100012), # inheriting from Azeroth Player
(100001,373),    # Command: gm fly
(100001,513),    # Command: maxskill
(100001,522),    # Command: respawn
(100001,523),    # Command: revive
(100001,517),    # Command: pinfo
(100001,526),    # Command: set skill
(100001,558),    # Command: modify rep
(100001,451),    # Command: lookup player
(100001,452),    # Command: lookup player ip
(100001,453),    # Command: lookup player account
(100001,454),    # Command: lookup player email
(100001,455),    # Command: lookup skill ( can inspect other players skills )
(100001,459),    # Command: lookup tele
(100001,556),    # Command: modify phase
(100001,417),    # Command: learn
(100001,418),    # Command: learn all
(100001,419),    # Command: learn all my
(100001,420),    # Command: learn all my class
(100001,421),    # Command: learn all my pettalents
(100001,422),    # Command: learn all my spells
(100001,423),    # Command: learn all my talents
(100001,424),    # Command: learn all gm
(100001,425),    # Command: learn all crafts
(100001,426),    # Command: learn all default
(100001,427),    # Command: learn all lang
(100001,428),    # Command: learn all recipes
(100001,429),    # COmmand: unlearn
(100001,251),    # Command: banlist ip
(100001,250),    # Command: banlist character
(100001,249),    # Command: banlist account
(100001,248),    # Command: banlist
(100001,247),    # Command: baninfo ip
(100001,246),    # Command: baninfo character
(100001,245),    # Command: baninfo account
(100001,244),    # Command: baninfo
(100001,521),    # Command: repairitems
(100001,711),    # Command: reset achievements
(100001,717),    # Command: reset all
(100001,712),    # Command: reset honor
(100001,713),    # Command: reset level
(100001,714),    # Command: reset spells
(100001,715),    # Command: reset stats
(100001,716),    # Command: reset talents
(100001,710),    # Command: reset
(100001,488),    # Command: additem
(100001,489),    # Command: additemset
(100001,287),    # Command: levelup
(100001,231),    # Command: achievement add
(100001,602),    # Command: quest
(100001,603),    # Command: quest add
(100001,604),    # Command: quest complete
(100001,605),    # Command: quest remove
(100001,606),    # Command: quest reward
(100001,593),    # Command: npcinfo
(100001,578),    # Command: npc follow
(100001,579),    # Command: npc follow stop
(100001,777),    # Command: mailbox
(100001,284),    # Command: character rename
(100001,274),    # Command: character customize
(100001,275),    # Command: character changefaction
(100001,276),    # Command: character changerace
(100001,529);    # Command: unaura


# TIER 2: Protector - Moderator
INSERT INTO `rbac_linked_permissions` VALUES
(100002,100001), # inherit from parent TIER
(100002,554),    # Command: modify money ( dangerous )
(100002,256),    # Command: unban playeraccount
(100002,255),    # Command: unban ip
(100002,254),    # Command: unban character
(100002,253),    # Command: unban account
(100002,252),    # Command: unban
(100002,243),    # Command: ban playeraccount
(100002,242),    # Command: ban ip
(100002,241),    # Command: ban character
(100002,240),    # Command: ban account
(100002,239),    # Command: ban
(100002,542),    # Command: morph
(100002,543),    # Command: demorph
(100002,532),    # Command: unmute
(100002,515);    # Command: mute



# TIER 3
INSERT INTO `rbac_linked_permissions` VALUES
(100003,193),    # inheriting from GM LVL 2 ( it shouldn't be necessary )
(100003,100002); # inherit from parent TIER

# Special: Story Master
INSERT INTO `rbac_linked_permissions` VALUES
(100010,100002), # inherit from TIER 2
(100010,596),    # Command: npc playemote
(100010,597),    # Command: npc say
(100010,598),    # Command: npc textemote
(100010,599),    # Command: npc whisper
(100010,600);    # Command: npc yell


# Special: test realm player
INSERT INTO `rbac_linked_permissions` VALUES
(100011,195), # inheriting from PLAYER ( it shouldn't be necessary but needed for research )
(100011,291), # Command: cheat
(100011,294), # Command: cheat explore
(100011,298), # Command: cheat taxi
(100011,377), # Command: go
(100011,378), # Command: go creature
(100011,442), # Command: lookup
(100011,447), # Command: lookup item
(100011,488), # Command: additem
(100011,489), # Command: additemset
(100011,287), # Command: levelup
(100011,554), # Command: modify money ( dangerous )
(100011,737); # Command: tele

# Special: test realm GM
INSERT INTO `rbac_linked_permissions` VALUES
(100013,193),     # inheriting from GM LVL 2 ( it shouldn't be necessary but needed for research )
(100013,100011),  # inherit from test player
(100013,498),     # Command: damage
(100013,500),     # Command: die
(100013,772),     # Command: wp unload
(100013,771),     # Command: wp modify
(100013,770),     # Command: wp load
(100013,769),     # Command: wp event
(100013,768),     # Command: wp add
(100013,595),     # Command: npc move
(100013,591),     # Command: npc set spawntime
(100013,590),     # Command: npc set spawndist
(100013,589),     # Command: npc set phase
(100013,588),     # Command: npc set movetype
(100013,587),     # Command: npc set model
(100013,586),     # Command: npc set link
(100013,585),     # Command: npc set level
(100013,584),     # Command: npc set flag
(100013,583),     # Command: npc set factionid
(100013,580),     # Command: npc set
(100013,579),     # Command: npc add follow stop
(100013,578),     # Command: npc add follow
(100013,577),     # Command: npc add delete item
(100013,576),     # Command: npc add delete
(100013,575),     # Command: npc add temp
(100013,574),     # Command: npc add move
(100013,573),     # Command: npc add item
(100013,572),     # Command: npc add formation
(100013,399),     # Command: gobject turn
(100013,397),     # Command: gobject set state
(100013,396),     # Command: gobject set phase
(100013,395),     # Command: gobject set
(100013,393),     # Command: gobject move
(100013,391),     # Command: gobject delete
(100013,390),     # Command: gobject add temp
(100013,389),     # Command: gobject add
(100013,370),     # Command: event stop
(100013,369);     # Command: event start

# Special: Azeroth player
INSERT INTO `rbac_linked_permissions` VALUES
(100012,195), # inheriting from PLAYER ( it shouldn't be necessary but needed for research )
(100012,309),  # Command: debug hostil
(100012,442),  # Command: lookup
(100012,443),  # Command: lookup area
(100012,444),  # Command: lookup creature
(100012,445),  # Command: lookup event
(100012,446),  # Command: lookup faction
(100012,447),  # Command: lookup item
(100012,448),  # Command: lookup itemset
(100012,449),  # Command: lookup object
(100012,450),  # Command: lookup quest
(100012,456),  # Command: lookup spell
(100012,457),  # Command: lookup spell id
(100012,458),  # Command: lookup taxinode
(100012,460),  # Command: lookup title
(100012,461),  # Command: lookup map
(100012,718),  # Command: server
(100012,1000), # Command: qc
(100012,736);  # Command: server motd

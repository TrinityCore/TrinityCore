update creature_template set ScriptName = 'npc_mirror_image' where entry = 51337;

delete from creature_template_addon where entry = 51337;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(51337, 0, 0, 0, 1, 0, '69676');
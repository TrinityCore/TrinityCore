update creature_template set flags_extra = 130 where entry = 59738;
delete from creature_template_addon where entry = 59738;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(59738, 0, 0, 0, 1, 0, '122257 114918');
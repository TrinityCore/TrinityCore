UPDATE creature_template SET inhabitType = 4 WHERE entry in (56141, 55967, 56252, 55969, 55913, 55971, 56140, 55912, 57474, 119223, 117721, 55914, 56142, 56144, 56139, 56143, 55911, 56251, 57795, 55294, 58115, 57475, 56250);
UPDATE creature_template SET npcflag = 1, scriptname = "npc_dragon_soul_teleport" WHERE entry in (57288, 57289, 27328, 57882, 57379, 57287, 57377, 57378, 57443);

UPDATE creature SET position_x = -1765.66, position_y = -3034.35, position_z = -182.38, orientation = 3.52 WHERE guid = 343667;

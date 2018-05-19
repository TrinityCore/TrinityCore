DELETE FROM `access_requirement` WHERE
(mapId = 1358 AND difficulty = 0) OR
(mapId = 564 AND difficulty = 4) OR
(mapId = 603 AND difficulty = 3) OR
(mapId = 603 AND difficulty = 4) OR
(mapId = 269 AND difficulty = 24) OR
(mapId = 540 AND difficulty = 24) OR
(mapId = 547 AND difficulty = 24) OR
(mapId = 552 AND difficulty = 24) OR
(mapId = 557 AND difficulty = 24) OR
(mapId = 575 AND difficulty = 24) OR
(mapId = 576 AND difficulty = 24) OR
(mapId = 585 AND difficulty = 24) OR
(mapId = 602 AND difficulty = 24) OR
(mapId = 604 AND difficulty = 24) OR
(mapId = 619 AND difficulty = 24) OR
(mapId = 643 AND difficulty = 24) OR
(mapId = 657 AND difficulty = 24) OR
(mapId = 658 AND difficulty = 24) OR
(mapId = 670 AND difficulty = 24) OR
(mapId = 725 AND difficulty = 24) OR
(mapId = 755 AND difficulty = 24) OR
(mapId = 938 AND difficulty = 24) OR
(mapId = 959 AND difficulty = 24) OR
(mapId = 960 AND difficulty = 24) OR
(mapId = 961 AND difficulty = 24) OR
(mapId = 962 AND difficulty = 24) OR
(mapId = 994 AND difficulty = 24) OR
(mapId = 1011 AND difficulty = 24) OR
(mapId = 1516 AND difficulty = 1) OR
(mapId = 1571 AND difficulty = 1);

UPDATE spell_proc SET SpellPhaseMask = 2 WHERE spellid = 195255;

UPDATE npc_text SET BroadcastTextId0 = 0 WHERE BroadcastTextId0 IN (147197, 147233, 147226, 147228, 147229, 147222, 147231, 147223, 147224, 146022, 134345, 144262, 138522);

DELETE FROM `spell_target_position` WHERE id in (65486, 85263, 85264, 85265, 85266, 64027, 176245, 176241);

DELETE FROM graveyard_zone WHERE GhostZone = 1191;

DELETE FROM `fishing_loot_template` WHERE Entry IN (6256, 36794, 45188, 45190, 110274);
DELETE FROM `spell_loot_template` WHERE Entry IN (60445, 61177, 61288, 61500, 95399, 95406, 257630, 257631, 257632, 257633, 257634, 257635, 257636, 257637, 257638, 257639, 263148, 263149, 263150, 263151, 263152, 263153, 263154);
UPDATE reference_loot_template SET MinCount = 1 WHERE Entry = 104;

DELETE FROM `instance_encounters` WHERE entry IN (201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 224, 225, 226, 246, 247, 248, 249, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 329, 330, 331, 332, 334, 336, 338, 339, 340, 341, 369, 370, 371, 372, 373, 374, 375, 376, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 430, 431, 432, 433, 434, 435, 436, 437, 439, 440, 441, 443, 445, 494, 495, 496, 497, 498, 499, 500, 501, 502, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 541, 542, 543, 544, 545, 546, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 829, 830, 831, 832, 833, 834, 835, 836, 837, 838, 839, 840, 841, 842, 843, 844, 883, 1268, 1269);

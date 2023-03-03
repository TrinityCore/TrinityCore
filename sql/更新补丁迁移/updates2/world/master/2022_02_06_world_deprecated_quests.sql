/*
**************************
*    BfaCore Reforged    *
**************************
*/

-- Disable duplicate and deprecated quests
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (8330,8336,8345,8346,38315,33121,33746,34591);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1,8330,0,"","","Duplicate, deprecated quest - Solanian's Belongings"),
(1,8336,0,"","","Deprecated quest - A Fistful of Slivers"),
(1,8345,0,"","","Deprecated quest - The Shrine of Dath'Remar"),
(1,8346,0,"","","Deprecated quest - Thirst Unending"),
(1,38315,0,"","","Deprecated quest - 38315"),
(1,33121,0,"","","Deprecated quest - The Celestial Tournament"),
(1,33746,0,"","","Deprecated quest - Y'kish Joins the Party"),
(1,34591,0,"","","Deprecated quest - Clearing out the Shadows");
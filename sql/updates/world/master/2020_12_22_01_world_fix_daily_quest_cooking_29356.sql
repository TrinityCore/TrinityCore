/*
    issue https://www.bfacore.com/d/1000-i-need-to-cask-a-favor
    quest https://www.wowhead.com/quest=29356/i-need-to-cask-a-favor
*/

-- Entry AreaTrigger = 130000
REPLACE INTO `areatrigger_involvedrelation` VALUES (130000, 29356);
-- Guid in table aretrigger = 108 NOTE: we cant use 103, it is in use already. -Varjgard
REPLACE INTO `areatrigger` VALUES (108, 130000, 0, 1, -5039.081543, -810.489807, 495.129700, '');
REPLACE INTO `areatrigger_scripts` VALUES (130000, 'at_i_need_to_cask_a_favor');
REPLACE INTO `areatrigger_template` VALUES (130000, 0, 1, 15, 15, 0, 0, 0, 0, 'at_i_need_to_cask_a_favor', 0);
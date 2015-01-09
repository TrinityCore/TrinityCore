DELETE FROM `spell_script_names` WHERE `spell_id` IN (69672,69673);
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(69672,'spell_gen_sunreaver_disguise'),
(69673,'spell_gen_silver_covenant_disguise');

-- Update spells used on script. Now they are always casting the female spell,
-- since the spell script is fixed we should cast now the correct spell.
UPDATE `smart_scripts` SET `action_param1`=69672 WHERE `entryorguid`=36669 AND `action_type`=11 AND `action_param1`=70973;
UPDATE `smart_scripts` SET `action_param1`=69673 WHERE `entryorguid`=36670 AND `action_type`=11 AND `action_param1`=70971;
-- Set correct gossip menus ids for renewing the disguise
UPDATE `smart_scripts` SET `event_param1`=10858 WHERE `entryorguid`=36669 AND `event_param1`=10857;
UPDATE `smart_scripts` SET `event_param1`=10857 WHERE `entryorguid`=36670 AND `event_param1`=10858;

-- Gossip options were crossed. They should offer to cast the oposing faction disguise,instead of his own faction disguise.
UPDATE `gossip_menu_option` SET `option_text`="Would you renew my Covenant disguise?" WHERE `menu_id`=10857 AND `id`=1;
UPDATE `gossip_menu_option` SET `option_text`="Would you renew my Sunreaver disguise?" WHERE `menu_id`=10858 AND `id`=1;

-- Correct quest ids on conditios for showing the renew disguise option.
-- Also add a check for male disguise aura.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (10857,10858) AND `SourceEntry`=1;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10858,1,0,11,70973,0,0,0,'',NULL),
(15,10858,1,0,11,70974,0,0,0,'',NULL),
(15,10858,1,0,9,20439,0,0,0,'',NULL),
(15,10857,1,0,11,70971,0,0,0,'',NULL),
(15,10857,1,0,11,70972,0,0,0,'',NULL),
(15,10857,1,0,9,24451,0,0,0,'',NULL);

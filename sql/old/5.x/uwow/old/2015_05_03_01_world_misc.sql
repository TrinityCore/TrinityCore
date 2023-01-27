update creature_template set modelid2 = 0, flags_extra = 130 where entry in (53296, 53301, 53302);
delete from item_script_names where id = 71259;
INSERT INTO `item_script_names` (`Id`, `ScriptName`) VALUES (71259, 'item_leyara_locket');
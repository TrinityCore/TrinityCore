DELETE FROM `creature_ai_scripts` WHERE `creature_id` =19255;

UPDATE `conditions` SET `ErrorType`=173,`ErrorTextId`=0 WHERE `SourceTypeOrReferenceId` =17 AND `SourceEntry`=74222;

UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags` |0x1 WHERE `Id` IN (9884,9885,9886,9887);

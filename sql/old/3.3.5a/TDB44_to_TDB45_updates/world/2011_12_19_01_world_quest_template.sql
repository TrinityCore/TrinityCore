-- Quest: Arcane Refreshment only available for mages
UPDATE `quest_template` SET `RequiredClasses`=`RequiredClasses`|128 WHERE `Id`=7463;

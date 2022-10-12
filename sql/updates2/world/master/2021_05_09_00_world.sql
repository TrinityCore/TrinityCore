UPDATE `quest_template_addon` SET `SpecialFlags`=`SpecialFlags`&~32;

DELETE FROM `quest_template_addon` WHERE
  `MaxLevel`=0
  AND `AllowableClasses`=0
  AND `SourceSpellID`=0
  AND `PrevQuestID`=0
  AND `NextQuestID`=0
  AND `ExclusiveGroup`=0
  AND `RewardMailTemplateID`=0
  AND `RewardMailDelay`=0
  AND `RequiredSkillID`=0
  AND `RequiredSkillPoints`=0
  AND `RequiredMinRepFaction`=0
  AND `RequiredMaxRepFaction`=0
  AND `RequiredMinRepValue`=0
  AND `RequiredMaxRepValue`=0
  AND `ProvidedItemCount`=0
  AND `SpecialFlags`=0
  AND `ScriptName`='';

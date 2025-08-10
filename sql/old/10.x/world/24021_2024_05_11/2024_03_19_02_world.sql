-- Creature
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` = 54943;

DELETE FROM `creature_template_addon` WHERE `entry` IN (54567, 54943);

DELETE FROM `creature_addon` WHERE `guid` IN (450280, 450277, 450351, 450350);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(450280, 0, 0, 0, 0, 1, 1, 0, 512, 0, 0, 0, 0, '80797'), -- Aysa Cloudsinger - 80797 - Generic Quest Invisibility 5
(450277, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '80797'), -- Merchant Lorvo - 80797 - Generic Quest Invisibility 5
(450350, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '82358'), -- Merchant Lorvo - 82358 - Generic Quest Invisibility 6
(450351, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '80852'); -- Aysa Cloudsinger - 80852 - Generic Quest Invisibility 10

UPDATE `gossip_menu_option` SET `GossipOptionID`=39680, `VerifiedBuild`=53584 WHERE (`MenuID`=13060 AND `OptionID`=0);

-- Areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry`=7748;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7748, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=7748 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7748, 2, 0, 0, 46, 0, 100, 0, 7748, 0, 0, 0, 0, '', 86, 116221, 2, 10, 450277, 54943, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Trigger - Cast Area Trigger Dummy Timer Aura C');

DELETE FROM `smart_scripts` WHERE `entryorguid`=54943 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(54943, 0, 0, 0, 31, 0, 100, 0, 116221, 0, 1000, 1000, 0, '', 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merchant Lorvo - On Spellhit Target - Talk');

DELETE FROM `creature_text` WHERE `CreatureID`=54943;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(54943, 0, 0, 'Shhhh! Come quietly. She\'s practicing.', 12, 0, 100, 396, 0, 0, 59712, 0, 'Merchant Lorvo to Player');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=7748;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 7748, 2, 0, 1, 0, 116221, 0, 0, 1, 0, 0, '', 'Areatrigger 7748 only triggers when player has not aura 116221'),
(22, 1, 7748, 2, 0, 28, 0, 29410, 0, 0, 0, 0, 0, '', 'Areatrigger 7748 only triggers when player has completed quest 29410');

-- Quest
UPDATE `quest_template_locale` SET `LogDescription`='Recupera 6 suministros de entrenamiento de malandrines Hojámbar.', `QuestDescription`='Unos malandrines Hojámbar asaltaron mi carro y se llevaron casi todos los suministros de entrenamiento que traía. Siempre nos han dado problemas, pero nunca los había visto tan agresivos. No sé qué les ha pasado.$b$bTe lo ruego, ayúdame a recuperar mis suministros.', `VerifiedBuild`=53584 WHERE (`ID`=29424 AND `locale`='esES');
UPDATE `quest_template_locale` SET `QuestDescription`='Mi conductor salió corriendo tras los duendes, después de que nos atacaran. No creo que le hagan daño, pero lo necesito de vuelta para que me ayude a limpiar este desastre.$b$bLos siguió hacia los riscos del norte. Si vas en esa dirección, no tardarás en encontrarlo.', `VerifiedBuild`=53584 WHERE (`ID`=29419 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogTitle`='Más fuerte que el junco', `LogDescription`='Reúne 8 juncos parteleños duros.', `QuestDescription`='Reúne juncos de las charcas cercanas.$B$BNo preguntes por qué. Hazlo y observa los resultados.', `VerifiedBuild`=53584 WHERE (`ID`=29662 AND `locale`='esES');
UPDATE `quest_template_locale` SET `VerifiedBuild`=53584 WHERE (`locale`='esES' AND `ID` IN (46736,46735,46277));
UPDATE `quest_template_locale` SET `QuestDescription`='En muy poco tiempo me has demostrado que tienes el potencial de convertirte en $gun:una; gran $c. Los campos de entrenamiento ya pertenecen al pasado; ahora debes mostrar lo que vales enfrentándote a un desafío mucho mayor, uno que ninguno de mis estudiantes ha conseguido superar.$b$bQuiero que lleves a Huo, el espíritu del fuego, de vuelta al Templo de los Cinco Albores.$b$bMis otros dos discípulos más aventajados te ayudarán en esta tarea. La primera es Aysa Canción Etérea. Búscala en la charca que hay al oeste.', `VerifiedBuild`=53584 WHERE (`ID`=29410 AND `locale`='esES');

DELETE FROM `quest_offer_reward_locale` WHERE (`ID`=29410 AND `locale`='esES');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(29410, 'esES', '¿Has venido a ver a Aysa? No... No es buena idea interrumpirla durante sus ejercicios. No habla con nadie mientras se entrena.$b$bMientras tanto, ¿te importaría ayudarme? He tenido mala suerte con los duendes del bosque.', 53584);

DELETE FROM `quest_request_items_locale` WHERE (`locale`='esES' AND `ID` IN (29424,29419));
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(29424, 'esES', 'No te preocupes por hacerles daño a los duendes. En realidad no son más que plantas andantes: con el tiempo vuelven a brotar.', 53584),
(29419, 'esES', 'Debería haber tenido más cuidado.', 53584);

DELETE FROM `quest_template_addon` WHERE `ID` IN (29419, 29424);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(29419, 0, 0, 0, 29410, 29414, -29424, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(29424, 0, 0, 0, 29410, 29414, -29424, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

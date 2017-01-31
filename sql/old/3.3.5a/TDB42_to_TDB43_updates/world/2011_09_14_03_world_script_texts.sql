-- Quest: Tomb of the Lightbringer, make Anchorite Truuen speak Common not Draconic
UPDATE `script_texts` SET `language`=7 WHERE `comment` LIKE 'npc_anchorite_truuen%' AND `language`=11;

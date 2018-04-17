-- Table `playercreateinfo_action`
-- Human
DELETE FROM playercreateinfo_action WHERE (race='1') AND (class='3') AND (button='0'); INSERT INTO playercreateinfo_action(race,class,button,action) VALUES ('1', '3', '0', '193455');
-- Dwarf
DELETE FROM playercreateinfo_action WHERE (race='3') AND (class='3') AND (button='0'); INSERT INTO playercreateinfo_action(race,class,button,action) VALUES ('3', '3', '0', '193455');
-- Night Elves
DELETE FROM playercreateinfo_action WHERE (race='4') AND (class='3') AND (button='0'); INSERT INTO playercreateinfo_action(race,class,button,action) VALUES ('4', '3', '0', '193455');
-- Gnomes
DELETE FROM playercreateinfo_action WHERE (race='7') AND (class='3') AND (button='0'); INSERT INTO playercreateinfo_action(race,class,button,action) VALUES ('7', '3', '0', '193455');
-- Draenei
DELETE FROM playercreateinfo_action WHERE (race='11') AND (class='3') AND (button='0'); INSERT INTO playercreateinfo_action(race,class,button,action) VALUES ('11', '3', '0', '193455');
-- Worgens
DELETE FROM playercreateinfo_action WHERE (race='22') AND (class='3') AND (button='0'); INSERT INTO playercreateinfo_action(race,class,button,action) VALUES ('22', '3', '0', '193455');

-- Table `quest_template_addon`
UPDATE quest_template_addon SET PrevQuestID='28817' WHERE (ID='26391');

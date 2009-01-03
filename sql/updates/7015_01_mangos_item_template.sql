ALTER TABLE db_version CHANGE COLUMN required_7002_01_mangos_spell_chain required_7015_01_mangos_item_template bit;

UPDATE item_template
    SET maxcount = 0 WHERE maxcount > 32000;

UPDATE item_template
    SET stackable = 0 WHERE stackable > 32000;

ALTER TABLE item_template
    CHANGE COLUMN maxcount  maxcount  smallint(5) NOT NULL default '-1',
    CHANGE COLUMN stackable stackable smallint(5) NOT NULL default '1';

UPDATE item_template
    SET stackable = -1 WHERE stackable = 0;

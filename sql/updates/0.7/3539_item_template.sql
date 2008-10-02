ALTER TABLE `item_template`
  CHANGE `spellcooldown_1`         `spellcooldown_1`         int(30) NOT NULL default '-1',
  CHANGE `spellcategorycooldown_1` `spellcategorycooldown_1` int(30) NOT NULL default '-1',
  CHANGE `spellcooldown_2`         `spellcooldown_2`         int(30) NOT NULL default '-1',
  CHANGE `spellcategorycooldown_2` `spellcategorycooldown_2` int(30) NOT NULL default '-1',
  CHANGE `spellcooldown_3`         `spellcooldown_3`         int(30) NOT NULL default '-1',
  CHANGE `spellcategorycooldown_3` `spellcategorycooldown_3` int(30) NOT NULL default '-1',
  CHANGE `spellcooldown_4`         `spellcooldown_4`         int(30) NOT NULL default '-1',
  CHANGE `spellcategorycooldown_4` `spellcategorycooldown_4` int(30) NOT NULL default '-1',
  CHANGE `spellcooldown_5`         `spellcooldown_5`         int(30) NOT NULL default '-1',
  CHANGE `spellcategorycooldown_5` `spellcategorycooldown_5` int(30) NOT NULL default '-1',
  CHANGE `unk_203` `unk_203` int(10) NOT NULL default '0' AFTER `Extra`;

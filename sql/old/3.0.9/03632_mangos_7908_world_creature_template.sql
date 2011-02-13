ALTER TABLE creature_template ADD COLUMN unit_class tinyint(3) unsigned NOT NULL default '0' AFTER rangeattacktime;

UPDATE creature_template ct
JOIN creature c ON ct.entry=c.id
JOIN creature_addon ad ON c.guid=ad.guid
SET ct.unit_class=(ad.bytes0 & 0x0000FF00) >> 8
WHERE ct.entry=c.id AND ct.unit_class=0;

UPDATE creature_template ct
JOIN creature_template_addon ad ON ct.entry=ad.entry
SET ct.unit_class=(ad.bytes0 & 0x0000FF00) >> 8
WHERE ct.entry=ad.entry AND ct.unit_class=0;

UPDATE creature_template a1, creature_template a2 SET a1.unit_class=a2.unit_class WHERE a1.unit_class=0 AND a2.unit_class!=0 AND a1.entry=a2.heroic_entry;
UPDATE creature_template a1, creature_template a2 SET a1.unit_class=a2.unit_class WHERE a1.unit_class=0 AND a2.unit_class!=0 AND a2.entry=a1.heroic_entry;

ALTER TABLE creature_addon
  DROP COLUMN bytes0;

ALTER TABLE creature_template_addon
  DROP COLUMN bytes0;

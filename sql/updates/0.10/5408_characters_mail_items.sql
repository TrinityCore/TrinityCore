ALTER TABLE mail_items
  ADD COLUMN receiver int(11) unsigned NOT NULL default 0 COMMENT 'Character Global Unique Identifier' AFTER item_template;

UPDATE mail_items, mail
  SET mail_items.receiver = mail.receiver WHERE mail_items.mail_id = mail.id;

DELETE FROM item_instance WHERE guid IN (SELECT item_guid FROM mail_items WHERE mail_items.receiver = 0);
DELETE FROM mail_items WHERE mail_items.receiver = 0;

--
UPDATE trinity_string SET content_default = 'AIName: %s\r\nScriptName: %s\r\nScriptTag: %s\r\nScriptTagId: %u' WHERE entry = 5031;

ALTER TABLE creature 
  ADD COLUMN ScriptTag VARCHAR(64) DEFAULT NULL
DELETE FROM `command` WHERE `name` IN ('debug areatriggers');
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('debug areatriggers',1,'Syntax: .debug areatriggers\nToggle debug mode for areatriggers. In debug mode GM will be notified if reaching an areatrigger');
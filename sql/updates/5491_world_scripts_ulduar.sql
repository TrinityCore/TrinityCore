INSERT INTO creature_template (entry, vehicleid) VALUES
(32930, 328) # Kologarn
ON DUPLICATE KEY UPDATE
vehicleid = VALUES(vehicleid);
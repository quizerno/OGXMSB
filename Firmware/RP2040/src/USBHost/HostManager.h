
 	bool is_hid_gamepad(const uint8_t* report_desc, uint16_t desc_len)
 	{
 		std::array<uint8_t, 6> start_bytes = { 0x05, 0x01, 0x09, 0x05, 0xA1, 0x01 };
 		if (desc_len < start_bytes.size())
 		{
 			return false;
 		}
 		for (size_t i = 0; i < start_bytes.size(); ++i)
 		{
 			if (report_desc[i] != start_bytes[i])
 			{
 				return false;
 			}
 		}
 		return true;
 	}
+
+	bool is_hid_keyboard(const uint8_t* report_desc, uint16_t desc_len)
+	{
+		// Typical boot protocol keyboard descriptor starts with: Usage Page (Generic Desktop), Usage (Keyboard)
+		std::array<uint8_t, 6> start_bytes = { 0x05, 0x01, 0x09, 0x06, 0xA1, 0x01 };
+		if (desc_len < start_bytes.size())
+		{
+			return false;
+		}
+		for (size_t i = 0; i < start_bytes.size(); ++i)
+		{
+			if (report_desc[i] != start_bytes[i])
+			{
+				return false;
+			}
+		}
+		return true;
+	}
*** End Patch

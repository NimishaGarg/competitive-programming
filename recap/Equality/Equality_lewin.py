print eval((lambda s: s[:7] + "=" + s[7:])(raw_input())) * "YES" or "NO"
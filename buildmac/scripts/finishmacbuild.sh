#!/bin/bash

install safejumper.icns Safejumper.app/Contents/Resources/
cp -R Resources/* Safejumper.app/Contents/Resources/
/usr/libexec/PlistBuddy -c "Set :CFBundleIconFile safejumper.icns" Safejumper.app/Contents/Info.plist
# macdeployqt Safejumper.app -verbose=1 
macdeployqt Safejumper.app -verbose=1 -codesign="Developer ID Application: Three Monkeys International Inc."
codesign -f -o library -s "Developer ID Application: Three Monkeys International Inc." Safejumper.app
sh scripts/package.sh 
hdiutil mount safejumper.dmg
scripts/ddstoregen.sh safejumper
hdiutil detach /Volumes/safejumper/

mv safejumper.dmg tmp.dmg
hdiutil convert -format UDRO -o safejumper.dmg tmp.dmg
rm tmp.dmg
hdiutil convert safejumper.dmg -format UDZO -imagekey -zlib-level=9 -o safejumper-compressed.dmg
rm safejumper.dmg
mv safejumper-compressed.dmg safejumper.dmg

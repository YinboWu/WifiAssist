#!/bin/bash

echo "UnInstall WifiAssist ..."
sudo rm -rf /usr/local/WifiAssist
sudo rm -rf /usr/local/bin/WifiAssist
sudo rm -rf /usr/local/share/applications/WifiAssist.desktop
sudo rm -rf /usr/share/polkit-1/actions/com.lzjqsdd.WifiAssist.policy
echo "Done."

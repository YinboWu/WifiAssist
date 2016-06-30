#!/bin/bash

echo "Install WifiAssist ..."
sudo mkdir /usr/local/WifiAssist
sudo cp WifiAssist wifi /usr/local/WifiAssist/
sudo cp -r bin/ etc/ img/ /usr/local/WifiAssist/
sudo ln -s /usr/local/WifiAssist/wifi /usr/local/bin/WifiAssist
echo "Done."

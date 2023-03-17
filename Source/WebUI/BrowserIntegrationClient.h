/**
 BrowserIntegrationClient is intended as a base class for any class
 that wants to communicate with a browser (although it can be used
 as an instance variable if preferred). There should only be one
 BrowserIntegration instance which is passed around as a reference.

 Each client is given a name, which should be unique and is prepended
 to any event names in order to namespace them.
*/
#pragma once

#include "BrowserIntegration.h"
#include "BrowserIntegrationClient.h"

#include <juce_core/juce_core.h>
#include <juce_gui_extra/juce_gui_extra.h>

class BrowserIntegrationClient
{
public:
  BrowserIntegrationClient (juce::String clientName, BrowserIntegration& browserIntegration);

  void registerBrowserCallback (juce::String name, BrowserCallback callback);
  void sendEventToBrowser (juce::String eventType, juce::var data, bool suppressLog = false);

protected:
  juce::String clientName;
  BrowserIntegration& browserIntegration;
};

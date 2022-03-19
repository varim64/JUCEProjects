/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Distortion1AudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Slider::Listener
{
public:
    Distortion1AudioProcessorEditor (Distortion1AudioProcessor&);
    ~Distortion1AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    
    void resized() override;

private:

    void sliderValueChanged (juce::Slider* slider) override;

    juce::Slider driveKnob;
    juce::Slider rangeKnob;
    juce::Slider blendKnob;
    juce::Slider volumeKnob;

//learn unique_ptr, shared_ptr, prefer_unique_ptr
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> driveAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> rangeAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> blendAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> volumeAttachment;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Distortion1AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Distortion1AudioProcessorEditor)
};

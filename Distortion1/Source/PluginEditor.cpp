/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Distortion1AudioProcessorEditor::Distortion1AudioProcessorEditor (Distortion1AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
    driveAttachment(new juce::AudioProcessorValueTreeState::SliderAttachment(p.getState(), "drive", driveKnob)),
    rangeAttachment(new juce::AudioProcessorValueTreeState::SliderAttachment(p.getState(), "range", rangeKnob)),
    blendAttachment(new juce::AudioProcessorValueTreeState::SliderAttachment(p.getState(), "blend", blendKnob)),
    volumeAttachment(new juce::AudioProcessorValueTreeState::SliderAttachment(p.getState(), "volume", volumeKnob))
//look up c++ member variable initialization
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 200);

    driveKnob.setSliderStyle(juce::Slider::Rotary);
    driveKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    driveKnob.setPopupDisplayEnabled(true, true, this);
    driveKnob.setTextValueSuffix("Drive");
    driveKnob.setValue(0.0);
    addAndMakeVisible(&driveKnob);

    rangeKnob.setSliderStyle(juce::Slider::Rotary);
    rangeKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    rangeKnob.setPopupDisplayEnabled(true, true, this);
    rangeKnob.setTextValueSuffix("Drive");
    rangeKnob.setValue(0.0);
    addAndMakeVisible(&rangeKnob);

    blendKnob.setSliderStyle(juce::Slider::Rotary);
    blendKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    blendKnob.setPopupDisplayEnabled(true, true, this);
    blendKnob.setTextValueSuffix("Drive");
    blendKnob.setValue(0.0);
    addAndMakeVisible(&blendKnob);

    volumeKnob.setSliderStyle(juce::Slider::Rotary);
    volumeKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    volumeKnob.setPopupDisplayEnabled(true, true, this);
    volumeKnob.setTextValueSuffix("Drive");
    volumeKnob.setValue(0.0);
    addAndMakeVisible(&volumeKnob);
}



Distortion1AudioProcessorEditor::~Distortion1AudioProcessorEditor()
{
}

//==============================================================================
void Distortion1AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void Distortion1AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    driveKnob.setBounds(((getWidth() / 5 ) * 1)  - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
    rangeKnob.setBounds(((getWidth() / 5 ) * 2)  - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
    blendKnob.setBounds(((getWidth() / 5 ) * 3)  - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
    volumeKnob.setBounds(((getWidth() / 5 ) * 4)  - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);

}

void Distortion1AudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    //noteOnVel needs to be replaced with variables driveVar, rangeVar, etc from processor.h
    //tutorial: listeners and broadcasters probably has the info for this?
    //sliderValueChanged needs to update the value of variables for each slider, find some way to pass slider-specific variable to function? maybe?
    //at ~42min in video
}


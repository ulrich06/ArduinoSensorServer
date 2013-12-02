/**
 * Consult and send data of all sensors whose
 * refresh time as elapsed. 
 * Must be call periodically to refresh sensors at appropriate 
 * frequency. 
 */
void queryAllSensors()
{
  int sid; 
  while ((sid = getNextSensorToQuery()) >= 0)
  {
    Serial.print("Time : "); Serial.println(millis());
    refreshSensorData(sid);
    updateNextSensorTime(sid);
  }
}


/**
 * Get sensor information and send its data by 
 * the help of its index.
 *
 * sid    : Sensor index.
 */ 
void refreshSensorData(int sid)
{
   // Get the data from the analog port.
   float value = 0;
   value = analogRead(getSensorPinNumber(sid));
   delay(100);
   
   // Print the data.
   Serial.print("Sensor "); Serial.print(getSensorName(sid));
   Serial.print(" sent data : "); Serial.println(value);
}
from flask import Flask, render_template
import iot_api_client as iot
from oauthlib.oauth2 import BackendApplicationClient
from requests_oauthlib import OAuth2Session

app = Flask(__name__)

CLIENT_ID = ''
CLIENT_SECRET = ''
THING_ID = ''
DEVICE_ID = ''
PROPERTY_ID = ''

oauth_client = BackendApplicationClient(client_id=CLIENT_ID)
token_url = "https://api2.arduino.cc/iot/v1/clients/token"
oauth = OAuth2Session(client=oauth_client)

token = oauth.fetch_token(
    token_url=token_url,
    client_id=CLIENT_ID,
    client_secret=CLIENT_SECRET,
    include_client_id=True,
    audience="https://api2.arduino.cc/iot",
)

client_config = iot.Configuration(host="https://api2.arduino.cc/iot")
client_config.access_token = token.get("access_token")
client = iot.ApiClient(client_config)
properties = iot.PropertiesV2Api(client)

def change_light(light_value):
    payload = {"value": light_value}
    try:
        properties.properties_v2_publish(THING_ID, PROPERTY_ID, payload)
    except Exception as e:
        print("Exception when calling PropertiesV2Api->propertiesV2Publish: %s\n" % e)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/change_light/<light_value>')
def change_light_route(light_value):
    change_light(light_value)
    return 'Light changed to ' + light_value

if __name__ == '__main__':
    app.run(debug=True)

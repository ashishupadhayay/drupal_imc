{
  "schemas": [
    "urn:ietf:params:scim:schemas:core:2.0:User","urn:ietf:params:scim:schemas:extension:enterprise:2.0:User"
  ],
  "name": {
    "givenName": "<?php print $data['fname'];?>",
    "familyName": "<?php print $data['lname'];?>"
  },
  "emails": {
    "value": "<?php print $data['email'];?>",
    "type": "home"
  },
  "addresses": {
    "type": "home",
    "region": "<?php print $data['region'];?>",
    "postalCode": "<?php print $data['postcode'];?>",
    "country": "<?php print $data['country'];?>"
  },
  "preferredLanguage": "27",
  "timezone": "65"
}
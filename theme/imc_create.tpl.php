{
  "schemas": ["urn:ietf:params:scim:schemas:core:2.0:User","urn:ietf:params:scim:schemas:extension:enterprise:2.0:User"],
  "id": "<?php print $data['id'];?>",
  "name":{
    "givenName": "<?php print $data['fname'];?>",
    "familyName": "<?php print $data['lname'];?>"
  },
  "emails":[
    {
      "value": "<?php print $data['email'];?>",
      "type": "home"
    }
  ],
  "addresses": [{
    "region": "<?php print $data['region'];?>",
    "postalCode": "<?php print $data['postcode'];?>",
    "country": "<?php print $data['country'];?>",
    "type": "home"
  }],
  "preferredLanguage": "27",
  "timezone": "65"
}
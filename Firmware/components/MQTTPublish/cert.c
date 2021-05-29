/* This is the CA certificate for the CA trust chain of
   Thingsboard in PEM format.

   The CA cert is the last cert in the chain output by the server.
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
 1 s:/C=US/O=Let's Encrypt/CN=Let's Encrypt Authority X3
   i:/O=Digital Signature Trust Co./CN=DST Root CA X3
 */


const char *srv_crt_rsa =
"-----BEGIN CERTIFICATE-----\r\n"
"MIIDdTCCAl2gAwIBAgIEa2lk1zANBgkqhkiG9w0BAQsFADBrMQswCQYDVQQGEwJE\r\n"
"RTELMAkGA1UECBMCQk4xDzANBgNVBAcTBkJlcmxpbjEQMA4GA1UEChMHZXB0ZWNv\r\n"
"bjETMBEGA1UECxMKR2x1ZWxvZ2ljczEXMBUGA1UEAxMOZ2x1ZWxvZ2ljcy5jb20w\r\n"
"HhcNMTgwNjEyMTQzNDUxWhcNNDUxMDI3MTQzNDUxWjBrMQswCQYDVQQGEwJERTEL\r\n"
"MAkGA1UECBMCQk4xDzANBgNVBAcTBkJlcmxpbjEQMA4GA1UEChMHZXB0ZWNvbjET\r\n"
"MBEGA1UECxMKR2x1ZWxvZ2ljczEXMBUGA1UEAxMOZ2x1ZWxvZ2ljcy5jb20wggEi\r\n"
"MA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCHj8FFIg2zZZvzAqNIz2nsm/7L\r\n"
"AbzMTwgZCQWNAJ3O0c9o/Vov2oYxtBwsQg7D+OHVH/GcSseNcrJ/wvG0tZFWxSsI\r\n"
"AafC4ZEKRL2TVgMxyaHsiAV+N1PuzZk6xZABZNG+vUaGmhQy6UrTzpQgWcDhzO+i\r\n"
"hsB3S1ndpESn8jHogikp4tOvrMzCIwVKP6qNUZt6t/P+KdJXHP1k37/2VIzoqOCR\r\n"
"h9WZr4wWgMNwRuo6msQbUV2tTCQIFkoEViEXc5PoFqssL8gly/Jt54YXD2roaut1\r\n"
"bZ10mkcy4LPrEFSWtCbqXrT/PoLABNkAEhqbVz/kLhjPAdBSEvPjS5kIORvxAgMB\r\n"
"AAGjITAfMB0GA1UdDgQWBBRUA06YYHSX9rgGLkWHsivJrjl9PTANBgkqhkiG9w0B\r\n"
"AQsFAAOCAQEAPPfHWnoNYc0zj4qJsf3LxkgK7e42vjqyYtFb6mpK+yItF60TlZUB\r\n"
"rtFQWe2UN4d7x6kZLq0BEG+T7zWbMqVS9aTVVkMYEbTuhQO43wtZGatv8l04+xb/\r\n"
"m1Tcx98wGdIVcSO4sfCTxnwaHQzFzPNVOfV0Cmbeh91UUSVBR3I3+5f91e/NQgko\r\n"
"8lLrahPMicytGuOHGZspvMXjNTvqYeK+x+Z7SC95iGKOeZuERMHVUjMgIf1guA+7\r\n"
"5rZLGYoVPeQQ4ay9R+CrViO5Yh94DSRTrkAxxa/LdiwE5llivQjWh42sRIMpWazu\r\n"
"xhIfi5UYWuJiZNAln6UIUk/c9IrD5avLGw==\r\n"
"-----END CERTIFICATE-----\r\n";
//const size_t mbedtls_test_srv_crt_rsa_len = sizeof( srv_crt_rsa );


const char *cli_crt_rsa =
"-----BEGIN CERTIFICATE-----\r\n"
"MIIDdTCCAl2gAwIBAgIEXDNjWzANBgkqhkiG9w0BAQsFADBrMQswCQYDVQQGEwJE\r\n"
"RTELMAkGA1UECBMCQk4xDzANBgNVBAcTBkJlcmxpbjEQMA4GA1UEChMHZXB0ZWNv\r\n"
"bjETMBEGA1UECxMKR2x1ZWxvZ2ljczEXMBUGA1UEAxMOZ2x1ZWxvZ2ljcy5jb20w\r\n"
"HhcNMTgwNjEyMTQzODQzWhcNNDUxMDI3MTQzODQzWjBrMQswCQYDVQQGEwJERTEL\r\n"
"MAkGA1UECBMCQk4xDzANBgNVBAcTBkJlcmxpbjEQMA4GA1UEChMHZXB0ZWNvbjET\r\n"
"MBEGA1UECxMKR2x1ZWxvZ2ljczEXMBUGA1UEAxMOZ2x1ZWxvZ2ljcy5jb20wggEi\r\n"
"MA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCUjVHxIr+sZlGPFkjE0Zm+9CN/\r\n"
"jCA0/TfCdOgjRMhZ7L5wbmfM+9Nav82z9/IITEyNNAsJ3+DkEbTKb5SVkUF8sx9b\r\n"
"bsAcpaM0PyCtKd9Ymd5XJ/Uy5Dd8kEPFvpIZMl2SlMDLjCuvdqJA9d7quKOuRcvW\r\n"
"kQq2mc5SNCjiQhp8YfqkyqH1auwNk+FOKPFPiBQAFzFpFwQi2HfZkl4nwgQlsRJ9\r\n"
"sJTba//y3Gy3PrK2AqiMKcTCe/TBscLYvxsOAFpBWzk5GxGIgESK1OY8NVwbPvc3\r\n"
"5dL7hHRzOJuPqPKFhM2r2wDtGoENA9M8FK2E7+vYlSWwy4F67acNHYff5YC5AgMB\r\n"
"AAGjITAfMB0GA1UdDgQWBBTOKukv3ruzvUTuDPuegFDJ7TR8PzANBgkqhkiG9w0B\r\n"
"AQsFAAOCAQEALAMXBdYE2CFwpG75wxFVTAOQY9fM8vFaLqSHhzu9ON9SgstXf9g3\r\n"
"zdEg5WiesincXvtD6ww1DDUSeH9psduJWw4bFxS9KGnfPxV3ZCARLQnq0P4AGxu0\r\n"
"dzXo7r/N3VtyoHKxRHNe8NqRleIo/2wYiu7pbr+nk1G0gMzR1GMrI5ONmdyeMSpN\r\n"
"BFS0Pp/mdjSPlQQVkCdNm0D2gbd/XqZtKr9FUvr/t2eb2GcAsxiqE9ukXTx7mEcl\r\n"
"acBraf94J9ral6CgMnjproOqL6OuUtj4k/eLLwkaUDeBkgBsDCy6GJALY98veXDT\r\n"
"rUedTRJcMriv4HAZDTTcO+bHIUTdjPDJcg==\r\n"
"-----END CERTIFICATE-----\r\n";
//const size_t mbedtls_test_cli_crt_rsa_len = sizeof( cli_crt_rsa );

const char *cli_key_rsa =
"-----BEGIN RSA PRIVATE KEY-----\r\n"
"MIIEowIBAAKCAQEAlI1R8SK/rGZRjxZIxNGZvvQjf4wgNP03wnToI0TIWey+cG5n\r\n"
"zPvTWr/Ns/fyCExMjTQLCd/g5BG0ym+UlZFBfLMfW27AHKWjND8grSnfWJneVyf1\r\n"
"MuQ3fJBDxb6SGTJdkpTAy4wrr3aiQPXe6rijrkXL1pEKtpnOUjQo4kIafGH6pMqh\r\n"
"9WrsDZPhTijxT4gUABcxaRcEIth32ZJeJ8IEJbESfbCU22v/8txstz6ytgKojCnE\r\n"
"wnv0wbHC2L8bDgBaQVs5ORsRiIBEitTmPDVcGz73N+XS+4R0czibj6jyhYTNq9sA\r\n"
"7RqBDQPTPBSthO/r2JUlsMuBeu2nDR2H3+WAuQIDAQABAoIBAF+SB7y+IVhVv3Tx\r\n"
"3kEZo/Mw+EGPsgzFOAFX2x0NnGQWJnMI5KkA/nns2fdFtiXWiI1zhQKGURYJuile\r\n"
"3dXXzKzgRHU7bEdB3Ry43FnrjXBgFaY2484o+vWdjqyCrVWejIrIPrz1YgmRplNq\r\n"
"m06hGVT+PGS/jYfqrc0/F2pxIr8QANt0h0IJ8+tFkTJezVQcvVqN/HlSY/2lfK9S\r\n"
"aRPjEZe66Kxh3TMX/QyzRtqk31AkUAVK8KPAFw1ASjHypkh95YOWH0OifHeFuGGd\r\n"
"BrKZMpGIsm4x52376prVWj0sjMzMsiz4jWcCP+sWnETja9dJTClbOtywf1XaH25n\r\n"
"5oLEg50CgYEA3tSaa6/IBrkfWNC8b/mEf7gswgFThBPaQGscbgZxCpLxfY7KV5cv\r\n"
"KWSTbgb5MOjoXqsZkJ0HJRAQ2KX8FcZ5FPJTMuVpBGpE94Fc9fhhxsTBONMg3Q0H\r\n"
"gRheZnsAnb4ijzNviW6M8H+6G6RZB1UdeZVDt1U+LrB7RGUNVaMkN3cCgYEAqqow\r\n"
"f8Wy44yumY09lcxNSucnzrdy+1sXrdrF0ITqSCE5JXlFAjB9zdzxEtvwzrR1xP80\r\n"
"DSAjn0CBUKywIuVr06Tf+IV8GQS92spTolTKmKR5Ym04GBLDpUZRd3u/8a5RHz7s\r\n"
"NVJjxhV0RXdr4yFGAwm+fTpG7zBehfEdml5ZdU8CgYA49GBv6+MVjNWtTtULTdyH\r\n"
"BJ00DUC6fpSHaJlAqhbUnBBrhkbDspnUW6evNMsWrEFQiS0koG5GE+Aqb+qJ6kvi\r\n"
"hbmsRaTdAwiTtpX7LLxZIMs+agB5X64uWfsu+HuE1idhMMVufDo78nmwPQagcCnz\r\n"
"fKptPrWBG4y2Q5nv7J4CKwKBgQCFmnAXRsSRYKu655gjsel8TtOZ/4ETBy/VWWPs\r\n"
"pnDmAKRFEteULDQAOgu7kNTGbP2ZN5QfBl78p7nUVywYVXQBHpx7aLxKtayPID8y\r\n"
"4KAtuOyRwiDcr6vbsd3K5OTRpX46ML8nyxTymA8K5r9d8sllTXaDgGDRlRMaVjSv\r\n"
"iVcM/wKBgH/mZnQO0y+VdtI9uULiKGH8HzaX+alsNXqEouc4XPaaSbdN5BHR3jhz\r\n"
"W6Tw15R3S5THXz6jSwbxoIWpfJ+ghTGKBwcTN3yBlFpF5OrpHQFRzUUwe1HgWYlR\r\n"
"85sg1hDnjqaA6kIdV19aWC9zDJr2+xjGHBCcQT8axiehpkTgiAJV\r\n"
"-----END RSA PRIVATE KEY-----\r\n";
//const size_t mbedtls_test_cli_key_rsa_len = sizeof( cli_key_rsa );






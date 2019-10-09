/***************************************************************************
 *
 * Copyright (C) 2018-2019 - ZmartZone Holding BV - www.zmartzone.eu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @Author: Hans Zandbelt - hans.zandbelt@zmartzone.eu
 *
 **************************************************************************/

#include <oauth2/mem.h>

#include "openidc_int.h"
#include "util_int.h"

oauth2_openidc_provider_t *oauth2_openidc_provider_init(oauth2_log_t *log)
{
	oauth2_openidc_provider_t *p = NULL;

	p = oauth2_mem_alloc(sizeof(oauth2_openidc_provider_t));
	if (p == NULL)
		goto end;

	p->issuer = NULL;
	p->authorization_endpoint = NULL;
	p->token_endpoint = NULL;
	p->token_endpoint_auth = NULL;
	p->jwks_uri = NULL;
	p->scope = NULL;
	p->client_id = NULL;
	p->client_secret = NULL;
	p->ssl_verify = true;

end:

	return p;
}

void oauth2_openidc_provider_free(oauth2_log_t *log,
				  oauth2_openidc_provider_t *p)
{
	if (p == NULL)
		goto end;

	if (p->issuer)
		oauth2_mem_free(p->issuer);
	if (p->authorization_endpoint)
		oauth2_mem_free(p->authorization_endpoint);
	if (p->token_endpoint)
		oauth2_mem_free(p->token_endpoint);
	if (p->token_endpoint_auth)
		oauth2_cfg_endpoint_auth_free(log, p->token_endpoint_auth);
	if (p->jwks_uri)
		oauth2_mem_free(p->jwks_uri);
	if (p->scope)
		oauth2_mem_free(p->scope);
	if (p->client_id)
		oauth2_mem_free(p->client_id);
	if (p->client_secret)
		oauth2_mem_free(p->client_secret);

	oauth2_mem_free(p);

end:

	return;
}

_OAUTH2_TYPE_IMPLEMENT_MEMBER_SET_GET(openidc, provider, issuer, char *, str)
_OAUTH2_TYPE_IMPLEMENT_MEMBER_SET_GET(openidc, provider, authorization_endpoint,
				      char *, str)
_OAUTH2_TYPE_IMPLEMENT_MEMBER_SET_GET(openidc, provider, token_endpoint, char *,
				      str)
_OAUTH2_TYPE_IMPLEMENT_MEMBER_SET_GET(openidc, provider, token_endpoint_auth,
				      oauth2_cfg_endpoint_auth_t *, ptr)
_OAUTH2_TYPE_IMPLEMENT_MEMBER_SET_GET(openidc, provider, jwks_uri, char *, str)
_OAUTH2_TYPE_IMPLEMENT_MEMBER_SET_GET(openidc, provider, scope, char *, str)
_OAUTH2_TYPE_IMPLEMENT_MEMBER_SET_GET(openidc, provider, client_id, char *, str)
_OAUTH2_TYPE_IMPLEMENT_MEMBER_SET_GET(openidc, provider, client_secret, char *,
				      str)
_OAUTH2_TYPE_IMPLEMENT_MEMBER_SET_GET(openidc, provider, ssl_verify, bool, bln)
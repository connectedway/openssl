/*
 * Copyright 1995-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

/*****************************************************************************
 *                                                                           *
 * The following macros/functions are PRIVATE to the record layer. They      *
 * should NOT be used outside of the record layer.                           *
 *                                                                           *
 *****************************************************************************/

#define MAX_WARN_ALERT_COUNT    5

/* Functions/macros provided by the RECORD_LAYER component */

#define RECORD_LAYER_get_write_sequence(rl)     ((rl)->write_sequence)
#define RECORD_LAYER_inc_empty_record_count(rl) ((rl)->empty_record_count++)
#define RECORD_LAYER_reset_empty_record_count(rl) \
                                                ((rl)->empty_record_count = 0)
#define RECORD_LAYER_get_empty_record_count(rl) ((rl)->empty_record_count)
#define DTLS_RECORD_LAYER_get_r_epoch(rl)       ((rl)->d->r_epoch)

int dtls_buffer_record(SSL_CONNECTION *s, TLS_RECORD *rec);

/* Macros/functions provided by the SSL3_RECORD component */

#define SSL3_RECORD_get_type(r)                 ((r)->type)
#define SSL3_RECORD_set_type(r, t)              ((r)->type = (t))
#define SSL3_RECORD_set_rec_version(r, v)       ((r)->rec_version = (v))
#define SSL3_RECORD_get_length(r)               ((r)->length)
#define SSL3_RECORD_set_length(r, l)            ((r)->length = (l))
#define SSL3_RECORD_add_length(r, l)            ((r)->length += (l))
#define SSL3_RECORD_sub_length(r, l)            ((r)->length -= (l))
#define SSL3_RECORD_get_data(r)                 ((r)->data)
#define SSL3_RECORD_set_data(r, d)              ((r)->data = (d))
#define SSL3_RECORD_get_input(r)                ((r)->input)
#define SSL3_RECORD_set_input(r, i)             ((r)->input = (i))
#define SSL3_RECORD_reset_input(r)              ((r)->input = (r)->data)
#define SSL3_RECORD_reset_data(r)               ((r)->data = (r)->input)
#define SSL3_RECORD_get_seq_num(r)              ((r)->seq_num)
#define SSL3_RECORD_get_off(r)                  ((r)->off)
#define SSL3_RECORD_set_off(r, o)               ((r)->off = (o))
#define SSL3_RECORD_add_off(r, o)               ((r)->off += (o))
#define SSL3_RECORD_get_epoch(r)                ((r)->epoch)

void SSL3_RECORD_release(SSL3_RECORD *r, size_t num_recs);
void SSL3_RECORD_set_seq_num(SSL3_RECORD *r, const unsigned char *seq_num);
__owur int ssl3_do_compress(SSL_CONNECTION *ssl, SSL3_RECORD *wr);
__owur int ssl3_do_uncompress(SSL_CONNECTION *ssl, SSL3_RECORD *rr);
__owur int ssl3_cbc_remove_padding_and_mac(size_t *reclen,
                                           size_t origreclen,
                                           unsigned char *recdata,
                                           unsigned char **mac,
                                           int *alloced,
                                           size_t block_size, size_t mac_size,
                                           OSSL_LIB_CTX *libctx);
__owur int tls1_cbc_remove_padding_and_mac(size_t *reclen,
                                           size_t origreclen,
                                           unsigned char *recdata,
                                           unsigned char **mac,
                                           int *alloced,
                                           size_t block_size, size_t mac_size,
                                           int aead,
                                           OSSL_LIB_CTX *libctx);
uint32_t ossl_get_max_early_data(SSL_CONNECTION *s);
int ossl_early_data_count_ok(SSL_CONNECTION *s, size_t length, size_t overhead,
                             int send);

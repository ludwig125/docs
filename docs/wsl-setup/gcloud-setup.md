# WSLで gcloud components updateをして [Errno 13] Permission deniedが出た

WSLのgcloud components updateをして [Errno 13] Permission deniedが出たはなし

完全にはまった問題があったので書く

環境：

- Windows10 WSL2
- Ubuntu 18.04.4 LTS

## 起きたこと

gcloud components updateをして [Errno 13] Permission deniedが出た

```
[~] $gcloud components update
略
ERROR: (gcloud.components.update) [Errno 13] Permission denied: '/mnt/c/wsl/google-cloud-sdk.staging/.install/.download': [/mnt/c/wsl/google-cloud-sdk/.install/.download]

Ensure you have the permissions to access the file and that the file is not in use.

```

<details><summary>全ログ</summary><div>


```
[~] $gcloud components update


Your current Cloud SDK version is: 293.0.0
You will be upgraded to version: 297.0.1

 ---------------------------------------------------------
|            These components will be updated.            |
 --------------------------------- ------------ ----------
|               Name              |  Version   |   Size   |
 --------------------------------- ------------ ----------
| BigQuery Command Line Tool      |     2.0.58 |  < 1 MiB |
| Cloud SDK Core Libraries        | 2020.06.17 | 14.9 MiB |
| Cloud Storage Command Line Tool |       4.51 |  3.5 MiB |
| anthoscli                       |     0.1.10 | 42.8 MiB |
| gcloud cli dependencies         | 2020.06.17 |  3.4 MiB |
| gcloud cli dependencies         | 2020.06.12 |  < 1 MiB |
 --------------------------------- ------------ ----------

The following release notes are new in this upgrade.
Please read carefully for information about new features, breaking changes,
and bugs fixed.  The latest full release notes can be viewed at:
  https://cloud.google.com/sdk/release_notes

297.0.1 (2020-06-17)
      o Fixed bug in gcloud app deploy command. This issue can be tracked at
        <https://issuetracker.google.com/issues/159109983>

297.0.0 (2020-06-16)
  Anthos
      o Added support for preferred authentication methods to anthos auth
        login command.

  BigQuery
      o Added support for splitting/merging capacity commitments.
      o Added support for autoscale based on reservations.
      o Fixed CLI json.loads error for Python 3.5.

  Compute Engine
      o Added --preemptible flag to gcloud compute instances set-scheduling.
      o Promoted --multi-writer flag of gcloud compute disks create to beta.

    Subscribe to these release notes at
    https://groups.google.com/forum/#!forum/google-cloud-sdk-announce
    (https://groups.google.com/forum/#!forum/google-cloud-sdk-announce).

    Note: Cloud SDK introduced support for Python 3 in release 274.0.0 and
    users are strongly encouraged to migrate to Python 3. Support for Python 2
    will be deprecated on July 31, 2020. See also Python 2 Sunset
    (https://cloud.google.com/python/docs/python2-sunset/) and Using Python 3
    (https://cloud.google.com/sdk/gcloud/reference/topic/startup).

296.0.1 (2020-06-10)
  Anthos
      o Fixed blocking bug in anthos auth login command.

296.0.0 (2020-06-09)
  Cloud SDK
      o Updated bundled Python executable to 3.7.5.

  Cloud Composer
      o Fixed a bug that causes backfill subcommand of gcloud composer
        environments run
    to be stuck indefinitely.
      o Updated gcloud composer environments run command to prefer GKE pods
        with 'Ready: true' condition state.

  Cloud Filestore
      o Updated gcloud beta filestore instances create
    and gcloud beta filestore instances update to include:
      o Added HIGH_SCALE_SSD, BASIC_HDD and BASIC_SSD tiers.
      o Added nfs-export-options to --file-share flag.
      o Support for NfsExportOptions. Run gcloud filestore --help or visit
        <https://cloud.google.com/filestore/docs/> to learn more.

  Cloud Firestore Emulator
      o Release Cloud Firestore emulator v1.11.4
        * Fixes bug for evaluating rules in query listening.
        * Fixes support for ?show_missing in listing collection.

  Cloud Resource Manager
      o Promoted gcloud projects create to beta.

  Cloud Run
      o Modified --vpc-connector and --clear-vpc-connector flags to be
        applicable for --platform=managed only.
      o Added --format export option to gcloud run services describe and
        gcloud run revisions describe, to output resources without
        deployment-specific metadata or status information.

  Compute Engine
      o Replaced coreos-cloud with fedora-coreos-cloud in the list of public
        image projects for --standard-images flag of gcloud compute images
        list.
      o Promoted gcloud compute commitments create-license to beta.
      o Added flag --instance-update-minimal-action flag to gcloud beta
        compute instance-groups managed instance-configs
        <create|update|delete>.

  Kubernetes Engine
      o Added --master-logs and '--enable-master-metrics' flags to gcloud
        beta container clusters to enable sending master logs and metrics to
        Cloud Operations (fka Stackdriver).

    Subscribe to these release notes at
    https://groups.google.com/forum/#!forum/google-cloud-sdk-announce
    (https://groups.google.com/forum/#!forum/google-cloud-sdk-announce).

    Note: Cloud SDK introduced support for Python 3 in release 274.0.0 and
    users are strongly encouraged to migrate to Python 3. Support for Python 2
    will be deprecated on July 31, 2020. See also Python 2 Sunset
    (https://cloud.google.com/python/docs/python2-sunset/) and Using Python 3
    (https://cloud.google.com/sdk/gcloud/reference/topic/startup).

295.0.0 (2020-06-02)
  Anthos
      o Added gcloud anthos apply command to beta. This command declaratively
        applies Config Connector resource configurations.
      o Added gcloud anthos export command to beta. This command exports
        Config Connector resource configurations of existing Google Kubernetes
        Engine clusters.

  Cloud Memorystore
      o Enabled support for Redis version 5.0. Added redis_5_0 as a new
        option for --redis_version flag of gcloud redis instances create.
      o Added gcloud redis instances upgrade to upgrade a Memorystore Redis
        instance to a specified Redis version.

  Cloud Pub/Sub
      o Rename --filter flag of gcloud pubsub subscriptions create to
        --message-filter. This is done to avoid confusion with --filter flag of
        <https://cloud.google.com/sdk/gcloud/reference/topic/filters>.
      o Promoted --message-filter flag of gcloud pubsub subscriptions create
        to beta. This feature allows users to specify a filter expression on a
        Cloud Pub/Sub subscription which will automatically drop messages.

  Compute Engine
      o Promoted gcloud compute instance-groups managed describe-instance to
        beta.
      o Added --accelerator flag to gcloud beta compute instances
        create-with-container.
      o Promoted --private-ipv6-google-access-type flag of gcloud compute
        instances <create|create-with-container> to GA.
      o Promoted --private-ipv6-google-access-type flag of gcloud compute
        instance-templates <create|create-with-container> to GA.
      o Promoted --private-ipv6-google-access-type flag of gcloud compute
        networks subnets <create|update> to GA.
      o Added --interface flag to gcloud beta compute disks create.
      o Added --interface flag to gcloud beta compute instances attach-disk.
      o Added interface key to --disk key of gcloud beta compute instances
        create.

  Game Servers
      o Added --description to gcloud <alpha|beta> game servers
        <clusters/realms/deployments> update to allow updating description for
        resources.

    Subscribe to these release notes at
    https://groups.google.com/forum/#!forum/google-cloud-sdk-announce
    (https://groups.google.com/forum/#!forum/google-cloud-sdk-announce).

    Note: Cloud SDK introduced support for Python 3 in release 274.0.0 and
    users are strongly encouraged to migrate to Python 3. Support for Python 2
    will be deprecated on July 31, 2020. See also Python 2 Sunset
    (https://cloud.google.com/python/docs/python2-sunset/) and Using Python 3
    (https://cloud.google.com/sdk/gcloud/reference/topic/startup).

294.0.0 (2020-05-27)
  Breaking Changes
      o **(Secret Manager)** Modified gcloud secrets beta command group to
        use the Secret Manager v1 API. The --uri flag now formats output to
        begin with https://secretmanager.googleapis.com/v1/ instead of
        https://secretmanager.googleapis.com/v1beta1/ when used with the
        following commands:
        * gcloud beta secrets list
        * gcloud beta locations list
        * gcloud beta secrets versions list

  AI Platform
      o Added --kms-key to gcloud <alpha|beta> ai-platform jobs submit
        training to allow specifying a customer-managed encryption key for a
        training job.

  Cloud Pub/Sub
      o Promoted configurable retry-related flags in gcloud pubsub
        subscriptions create and gcloud pubsub subscriptions update to GA.

  Cloud Run
      o Change gcloud run services get-iam-policy, gcloud run services
        set-iam-policy, gcloud run services add-iam-policy-binding, and gcloud
        run services remove-iam-policy-binding to use the v1 api.

  Cloud Storage
      o Updated gsutil component to 4.51.

  Cloud Tasks
      o Promoted gcloud tasks queues create-pull-queue to beta.

  Compute Engine
      o Changed default action from RESTART to REPLACE for --update-instance
        flag of gcloud compute instance-groups managed instance-configs
        create|update.
      o Promoted --maintenance-policy of gcloud compute sole-tenancy
        node-groups create to GA.

    Subscribe to these release notes at
    https://groups.google.com/forum/#!forum/google-cloud-sdk-announce
    (https://groups.google.com/forum/#!forum/google-cloud-sdk-announce).

Do you want to continue (Y/n)?  y

Creating update staging area
10%
20%
30%
35%
40%
45%
50%
55%
60%
65%
70%
75%
80%
85%
90%
95%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
ERROR: (gcloud.components.update) [Errno 13] Permission denied: '/mnt/c/wsl/google-cloud-sdk.staging/.install/.download': [/mnt/c/wsl/google-cloud-sdk/.install/.download]

Ensure you have the permissions to access the file and that the file is not in use.
[~] $
```


</div></details>

## 前提

[Linux 用のクイックスタート  \|  Cloud SDK のドキュメント  |  Google Cloud](https://cloud.google.com/sdk/docs/quickstart-linux?hl=ja)

> アーカイブをファイル システム上に展開

の箇所で、「ホームディレクトリをおすすめします」と書いてあったのでそれに従ってインストールした。

自分がWSLを使っていた時は`/mnt/c/wsl`という、Cドライブ直下に`wsl` というディレクトリをホームディレクトリにしていたので、

最初はこのようなインストールをした

```
$ tar zxvf google-cloud-sdk-293.0.0-linux-x86_64.tar.gz google-cloud-sdk
```

がこれでいろいろやっているうちに、
`gcloud components update` ができないという上述の問題に遭遇した



## 試したこと

以下のことを全部やってみたけどダメだった

https://stackoverflow.com/questions/49210830/gcloud-components-update-permission-denied
https://stackoverflow.com/questions/31220077/gcloud-installation-permission-issue-on-ubuntu-12-04/31247129#31247129


1. ./google-cloud-sdkディレクトリのパーミッションを自分にする
```
sudo chown -R $USER ./google-cloud-sdk
```

2. .config/gcloudディレクトリのパーミッションを自分にする
```
sudo chown -R $USER .config/gcloud
```

3. sudoをつけて実行してみる
```
sudo gcloud components update
```

4. pythonを3.6にしてみる(それまで3.7がデフォルトだった)
```
$sudo apt update
$sudo apt install python3.6

$python3.6 --version
Python 3.6.9
```

.zshrc(または.bashrc)に以下のaliasを追加

```
alias python=/usr/bin/python3.6
```


## 解決

gcloudを`/mnt/c/wsl/` ではなく `/home/$USER` という、WSLのデフォルトのホームディレクトリに入れ直したら解決した

まずはgcloudを削除


[Google Cloud SDK のアンインストール  \|  Cloud SDK のドキュメント](https://cloud.google.com/sdk/docs/uninstall-cloud-sdk?hl=ja)
に従って、以下のディレクトリを削除

```
$gcloud info --format='value(installation.sdk_root)'
# -> /mnt/c/wsl/google-cloud-sdk
$gcloud info --format='value(config.paths.global_config_dir)'
# -> /mnt/c/wsl/.config/gcloud
```

.zshrcに書き込まれていた以下の記述も削除
```
# The next line updates PATH for the Google Cloud SDK.
if [ -f '/mnt/c/wsl/google-cloud-sdk/path.zsh.inc' ]; then . '/mnt/c/wsl/google-cloud-sdk/path.zsh.inc'; fi

# The next line enables shell command completion for gcloud.
if [ -f '/mnt/c/wsl/google-cloud-sdk/completion.zsh.inc' ]; then . '/mnt/c/wsl/google-cloud-sdk/completion.zsh.inc'; fi
```

tarの展開先を `/home/＄USER` に変更
```
$ tar zxvf google-cloud-sdk-293.0.0-linux-x86_64.tar.gz /home/$USER/google-cloud-sdk
```

新しいgcloudのパス
```
$which gcloud
/home/ludwig125/google-cloud-sdk/bin/gcloud
```

こうしたら `gcloud components update` ができるようになった

ちなみに `gcloud --quiet components update` とするといちいち 【y/N】と聞かれなくなるので便利
